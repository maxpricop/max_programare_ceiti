package studiul_individual_1.controllers;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.stage.Window;
import studiul_individual_1.model.Patient;
import studiul_individual_1.services.PatientService;

import java.util.List;
import java.util.stream.Collectors;

public class MainController {

	@FXML
	private TableView<Patient> table;
	@FXML
	private TableColumn<Patient, Integer> colId;
	@FXML
	private TableColumn<Patient, String> colFirstName;
	@FXML
	private TableColumn<Patient, String> colLastName;
	@FXML
	private TableColumn<Patient, String> colPatronymic;
	@FXML
	private TableColumn<Patient, String> colAddress;
	@FXML
	private TableColumn<Patient, String> colPhone;
	@FXML
	private TableColumn<Patient, Integer> colPolicy;
	@FXML
	private TableColumn<Patient, String> colSection;
	@FXML
	private TableColumn<Patient, String> colDiagnosis;

	private final PatientService service = new PatientService();
	private final ObservableList<Patient> data = FXCollections.observableArrayList();

	@FXML
	public void initialize() {
		colId.setCellValueFactory(c -> new javafx.beans.property.ReadOnlyObjectWrapper<>(c.getValue().getId()));
		colFirstName.setCellValueFactory(c -> new javafx.beans.property.SimpleStringProperty(c.getValue().getFirstName()));
		colLastName.setCellValueFactory(c -> new javafx.beans.property.SimpleStringProperty(c.getValue().getLastName()));
		colPatronymic.setCellValueFactory(c -> new javafx.beans.property.SimpleStringProperty(c.getValue().getPatronymic()));
		colAddress.setCellValueFactory(c -> new javafx.beans.property.SimpleStringProperty(c.getValue().getAddress()));
		colPhone.setCellValueFactory(c -> new javafx.beans.property.SimpleStringProperty(c.getValue().getPhone()));
		colPolicy.setCellValueFactory(c -> new javafx.beans.property.ReadOnlyObjectWrapper<>(c.getValue().getPolicyNumber()));
		colSection.setCellValueFactory(c -> new javafx.beans.property.SimpleStringProperty(c.getValue().getSection()));
		colDiagnosis.setCellValueFactory(c -> new javafx.beans.property.SimpleStringProperty(c.getValue().getDiagnosis()));

		table.setItems(data);
		showAll();
	}

	private Window window() {
		return table.getScene().getWindow();
	}

	@FXML
	private void onSync() {
		try {
			service.sync();
			showAll();
			MessageDialogController.showInfo(window(), "Sincronizare completă.");
		} catch (Exception e) {
			MessageDialogController.showError(window(), e.getMessage());
		}
	}

	@FXML
	private void onAddPrimary() {
		PatientDialogController.show(window(), null).ifPresent(p -> {
			try {
				service.addPatient(p);
				showAll();
				MessageDialogController.showInfo(window(), "Pacientul a fost adăugat.");
			} catch (Exception e) {
				MessageDialogController.showError(window(), e.getMessage());
			}
		});
	}

	@FXML
	private void onModifyPrimary() {
		Patient sel = table.getSelectionModel().getSelectedItem();
		if (sel == null) { MessageDialogController.showInfo(window(), "Niciun pacient selectat."); return; }

		PatientDialogController.show(window(), sel).ifPresent(p -> {
			try {
				service.updatePatient(sel.getId(), p);
				showAll();
				MessageDialogController.showInfo(window(), "Pacientul a fost actualizat.");
			} catch (Exception e) {
				MessageDialogController.showError(window(), e.getMessage());
			}
		});
	}

	@FXML
	private void onDeletePrimary() {
		Patient sel = table.getSelectionModel().getSelectedItem();
		if (sel == null) { MessageDialogController.showInfo(window(), "Niciun pacient selectat."); return; }

		if (ConfirmDialogController.show(window(), "Confirmare", "Ștergi pacientul selectat?")) {
			try {
				service.deletePatient(sel.getId());
				showAll();
				MessageDialogController.showInfo(window(), "Pacientul a fost șters.");
			} catch (Exception e) {
				MessageDialogController.showError(window(), e.getMessage());
			}
		}
	}

	@FXML
	private void onSearchByDiagnosisDialog() {
		SearchDialogController.show(window(), "Caută după diagnoză", "Diagnoză:").ifPresent(s -> data.setAll(service.getByDiagnosis(s)));
	}

	@FXML
	private void onSearchByPolicyRangeDialog() {
		SearchRangeDialogController.show(window()).ifPresent(arr -> data.setAll(service.getByPolicyRange(arr[0], arr[1])));
	}

	@FXML
	private void onSearchByPolicyDialog() {
		SearchDialogController.show(window(), "Caută poliță", "Număr poliță:").ifPresent(s -> {
			try {
				Patient p = service.getByPolicyNumber(Integer.parseInt(s));
				data.setAll(p == null ? List.of() : List.of(p));
			} catch (NumberFormatException e) {
				MessageDialogController.showError(window(), "Număr poliță invalid.");
			}
		});
	}

	@FXML
	private void onSearchBySectionDialog() {
		SearchDialogController.show(window(), "Caută secție", "Secție:").ifPresent(
				s -> data.setAll(service.getAll().stream().filter(p -> s.equalsIgnoreCase(p.getSection())).collect(Collectors.toList())));
	}

	@FXML
	private void onSearchByFirstNameDialog() {
		SearchDialogController.show(window(), "Caută prenume", "Prenume:").ifPresent(s -> data.setAll(service.getByFirstName(s)));
	}

	private void showAll() {
		data.setAll(service.getAll());
	}
}
