package studiul_individual_2.controllers;

import javafx.beans.property.ReadOnlyStringWrapper;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.TextInputDialog;
import studiul_individual_2.exceptions.VehicleDataFileMissingException;
import studiul_individual_2.exceptions.VehicleDataFormatException;
import studiul_individual_2.exceptions.VehicleValidationException;
import studiul_individual_2.model.Bus;
import studiul_individual_2.model.Metro;
import studiul_individual_2.model.Tram;
import studiul_individual_2.model.Vehicle;
import studiul_individual_2.services.VehicleService;

import java.io.IOException;
import java.nio.file.Path;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Optional;

/**
 * Controller for the main transport management view.
 */
public class MainController {

	@FXML
	private ComboBox<String> typeComboBox;

	@FXML
	private TextField vehicleNumberField;

	@FXML
	private TextField lineNameField;

	@FXML
	private TextField capacityField;

	@FXML
	private TextField ticketPriceField;

	@FXML
	private Label extraLabel;

	@FXML
	private TextField extraField;

	@FXML
	private Label statusLabel;

	@FXML
	private TableView<Vehicle> vehicleTable;

	@FXML
	private TableColumn<Vehicle, String> typeColumn;

	@FXML
	private TableColumn<Vehicle, String> vehicleNumberColumn;

	@FXML
	private TableColumn<Vehicle, String> lineNameColumn;

	@FXML
	private TableColumn<Vehicle, String> capacityColumn;

	@FXML
	private TableColumn<Vehicle, String> ticketPriceColumn;

	@FXML
	private TableColumn<Vehicle, String> detailsColumn;

	private final VehicleService vehicleService = new VehicleService(Path.of("data", "vehicles.txt"));
	private final ObservableList<Vehicle> tableData = FXCollections.observableArrayList();
	private final DecimalFormat decimalFormat = new DecimalFormat("#,##0.00",
			DecimalFormatSymbols.getInstance(new Locale.Builder().setLanguage("ro").setRegion("RO").build()));

	@FXML
	public void initialize() {
		configureTypeSelector();
		configureTable();
		refreshTable(vehicleService.getAllVehicles());
		setStatusMessage("Aplicatia este gata de utilizare.", false);
	}

	@FXML
	private void handleAddVehicle() {
		try {
			Vehicle vehicle = buildVehicleFromForm();
			vehicleService.addVehicle(vehicle);
			refreshTable(vehicleService.getAllVehicles());
			clearInputsAfterAdd();
			setStatusMessage("Vehiculul a fost adaugat cu succes.", false);
		} catch (VehicleValidationException | NumberFormatException exception) {
			setStatusMessage(exception.getMessage(), true);
			showErrorAlert("Date invalide", exception.getMessage());
		}
	}

	@FXML
	private void handleShowAll() {
		List<Vehicle> vehicles = vehicleService.getAllVehicles();
		refreshTable(vehicles);
		setStatusMessage("Afisare completa: " + vehicles.size() + " vehicule.", false);
	}

	@FXML
	private void handleShowAvailable() {
		List<Vehicle> availableVehicles = vehicleService.getAvailableVehicles();
		refreshTable(availableVehicles);

		if (availableVehicles.isEmpty()) { setStatusMessage("Nu exista vehicule disponibile momentan.", true); return; }

		setStatusMessage("Afisare vehicule disponibile: " + availableVehicles.size() + ".", false);
	}

	@FXML
	private void handleSelectedRevenue() {
		Vehicle selectedVehicle = vehicleTable.getSelectionModel().getSelectedItem();

		if (selectedVehicle == null) {
			setStatusMessage("Selectati un vehicul pentru calculul venitului.", true);
			showErrorAlert("Selectie lipsa", "Trebuie sa selectati un vehicul din tabel.");
			return;
		}

		Integer numberOfPassengers = requestPassengersCount("Venit vehicul selectat",
				"Introduceti numarul de calatori pentru vehiculul selectat:");
		if (numberOfPassengers == null) { setStatusMessage("Calculul venitului a fost anulat.", true); return; }

		try {
			double revenue = vehicleService.calculateRevenueFor(selectedVehicle, numberOfPassengers);
			setStatusMessage("Venitul zilnic pentru vehiculul selectat este " + formatMoney(revenue) + " lei.", false);
		} catch (VehicleValidationException exception) {
			setStatusMessage(exception.getMessage(), true);
			showErrorAlert("Date invalide", exception.getMessage());
		}
	}

	@FXML
	private void handleTotalRevenue() {
		List<Vehicle> vehicles = vehicleService.getAllVehicles();
		if (vehicles.isEmpty()) { setStatusMessage("Nu exista vehicule pentru calculul venitului total.", true); return; }

		List<Integer> passengersPerVehicle = new ArrayList<>();
		for (Vehicle vehicle : vehicles) {
			Integer passengers = requestPassengersCount("Venit total pe zi", "Calatori pentru vehiculul #" + vehicle.getVehicleNumber()
					+ " (" + vehicle.getTypeName() + ", " + vehicle.getRoute() + "):");

			if (passengers == null) { setStatusMessage("Calculul venitului total a fost anulat.", true); return; }

			passengersPerVehicle.add(passengers);
		}

		try {
			double totalRevenue = vehicleService.calculateTotalDailyRevenue(passengersPerVehicle);
			setStatusMessage("Venitul zilnic total al tuturor vehiculelor este " + formatMoney(totalRevenue) + " lei.", false);
		} catch (VehicleValidationException exception) {
			setStatusMessage(exception.getMessage(), true);
			showErrorAlert("Date invalide", exception.getMessage());
		}
	}

	@FXML
	private void handleSaveVehicles() {
		try {
			vehicleService.saveVehicles();
			setStatusMessage("Datele au fost salvate in " + vehicleService.getDataFilePath() + ".", false);
		} catch (IOException exception) {
			setStatusMessage("Salvarea a esuat: " + exception.getMessage(), true);
			showErrorAlert("Eroare la salvare", "Datele nu au putut fi salvate.");
		}
	}

	@FXML
	private void handleLoadVehicles() {
		try {
			vehicleService.loadVehicles();
			refreshTable(vehicleService.getAllVehicles());
			setStatusMessage("Datele au fost incarcate cu succes. Vehicule: " + vehicleService.getAllVehicles().size() + ".", false);
		} catch (VehicleDataFileMissingException exception) {
			setStatusMessage(exception.getMessage(), true);
			showErrorAlert("Fisier lipsa", exception.getMessage());
		} catch (VehicleDataFormatException exception) {
			setStatusMessage("Fisierul contine date invalide.", true);
			showErrorAlert("Date corupte", exception.getMessage());
		}
	}

	private void configureTypeSelector() {
		typeComboBox.setItems(FXCollections.observableArrayList("Autobuz", "Tramvai", "Metrou"));
		typeComboBox.getSelectionModel().selectFirst();
		updateExtraFieldMetadata(typeComboBox.getValue());

		typeComboBox.getSelectionModel().selectedItemProperty()
				.addListener((obs, oldValue, newValue) -> updateExtraFieldMetadata(newValue));
	}

	private void configureTable() {
		typeColumn.setCellValueFactory(cell -> new ReadOnlyStringWrapper(cell.getValue().getTypeName()));
		vehicleNumberColumn.setCellValueFactory(cell -> new ReadOnlyStringWrapper(Integer.toString(cell.getValue().getVehicleNumber())));
		lineNameColumn.setCellValueFactory(cell -> new ReadOnlyStringWrapper(cell.getValue().getRoute()));
		capacityColumn.setCellValueFactory(cell -> new ReadOnlyStringWrapper(Integer.toString(cell.getValue().getNumberOfSeats())));
		ticketPriceColumn.setCellValueFactory(cell -> new ReadOnlyStringWrapper(formatMoney(cell.getValue().getFare())));
		detailsColumn.setCellValueFactory(cell -> new ReadOnlyStringWrapper(cell.getValue().getSpecificDetails()));

		vehicleTable.setItems(tableData);
	}

	private Vehicle buildVehicleFromForm() throws VehicleValidationException {
		String selectedType = typeComboBox.getValue();
		int vehicleNumber = parseInteger(vehicleNumberField.getText(), "Numarul vehiculului trebuie sa fie un numar intreg.");
		String lineName = lineNameField.getText();
		int capacity = parseInteger(capacityField.getText(), "Numarul de locuri trebuie sa fie un numar intreg.");
		double ticketPrice = parseDouble(ticketPriceField.getText(), "Tariful trebuie sa fie numeric.");
		String extra = extraField.getText();

		if (selectedType == null || selectedType.isBlank()) { throw new VehicleValidationException("Selectati tipul vehiculului."); }

		if (extra == null || extra.trim().isEmpty()) {
			throw new VehicleValidationException("Completati campul suplimentar pentru tipul selectat.");
		}

		switch (selectedType) {
			case "Autobuz":
				return new Bus(vehicleNumber, capacity, lineName, ticketPrice, parseFuelType(extra));
			case "Tramvai":
				return new Tram(vehicleNumber, capacity, lineName, ticketPrice,
						parseInteger(extra, "Numarul de vagoane trebuie sa fie un numar intreg."));
			case "Metrou":
				return new Metro(vehicleNumber, capacity, lineName, ticketPrice,
						parseInteger(extra, "Numarul de statii trebuie sa fie un numar intreg."));
			default:
				throw new VehicleValidationException("Tipul vehiculului selectat nu este suportat.");
		}
	}

	private void updateExtraFieldMetadata(String selectedType) {
		if (selectedType == null) { return; }

		switch (selectedType) {
			case "Autobuz": {
				extraLabel.setText("Tip combustibil");
				extraField.setPromptText("diesel / electric / hybrid");
				break;
			}
			case "Tramvai": {
				extraLabel.setText("Numar vagoane");
				extraField.setPromptText("ex: 4");
				break;
			}
			case "Metrou": {
				extraLabel.setText("Numar statii");
				extraField.setPromptText("ex: 18");
				break;
			}
			default: {
				extraLabel.setText("Detalii");
				extraField.setPromptText("");
			}
		}
	}

	private int parseInteger(String rawValue, String errorMessage) throws VehicleValidationException {
		try {
			return Integer.parseInt(rawValue.trim());
		} catch (NumberFormatException exception) {
			throw new VehicleValidationException(errorMessage, exception);
		}
	}

	private double parseDouble(String rawValue, String errorMessage) throws VehicleValidationException {
		try {
			return Double.parseDouble(rawValue.trim());
		} catch (NumberFormatException exception) {
			throw new VehicleValidationException(errorMessage, exception);
		}
	}

	private String parseFuelType(String rawValue) throws VehicleValidationException {
		String normalizedValue = rawValue.trim().toLowerCase(Locale.ROOT);

		if (Bus.VALID_FUELS.contains(normalizedValue)) return normalizedValue;

		throw new VehicleValidationException("Pentru autobuz folositi: diesel, electric sau hybrid.");
	}

	private Integer requestPassengersCount(String title, String prompt) {
		while (true) {
			TextInputDialog dialog = new TextInputDialog("0");
			dialog.setTitle(title);
			dialog.setHeaderText(null);
			dialog.setContentText(prompt);

			Optional<String> result = dialog.showAndWait();
			if (result.isEmpty()) return null;

			try {
				int passengers = Integer.parseInt(result.get().trim());
				if (passengers < 0) throw new NumberFormatException();
				return passengers;
			} catch (NumberFormatException exception) {
				showErrorAlert("Valoare invalida", "Introduceti un numar intreg pozitiv sau 0.");
			}
		}
	}

	private void refreshTable(List<Vehicle> vehicles) {
		tableData.setAll(vehicles);
	}

	private void clearInputsAfterAdd() {
		vehicleNumberField.clear();
		lineNameField.clear();
		capacityField.clear();
		ticketPriceField.clear();
		extraField.clear();
	}

	private String formatMoney(double value) {
		return decimalFormat.format(value);
	}

	private void setStatusMessage(String message, boolean error) {
		statusLabel.setText(message);
		statusLabel.getStyleClass().removeAll("status-success", "status-error");
		statusLabel.getStyleClass().add(error ? "status-error" : "status-success");
	}

	private void showErrorAlert(String title, String message) {
		Alert alert = new Alert(Alert.AlertType.ERROR);
		alert.setTitle(title);
		alert.setHeaderText(null);
		alert.setContentText(message);
		alert.showAndWait();
	}
}
