package studiul_individual_2.services;

import studiul_individual_2.exceptions.VehicleDataFileMissingException;
import studiul_individual_2.exceptions.VehicleDataFormatException;
import studiul_individual_2.exceptions.VehicleValidationException;
import studiul_individual_2.model.Bus;
import studiul_individual_2.model.Metro;
import studiul_individual_2.model.Tram;
import studiul_individual_2.model.Vehicle;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

/**
 * Handles file persistence for vehicle entities.
 */
public class VehicleFileService {

	private static final String DELIMITER = "|";
	private static final int RECORD_SIZE = 6;

	private final Path dataFilePath;

	public VehicleFileService(Path dataFilePath) {
		this.dataFilePath = Objects.requireNonNull(dataFilePath, "Data file path cannot be null.");
	}

	public Path getDataFilePath() {
		return dataFilePath;
	}

	public void saveVehicles(List<Vehicle> vehicles) throws IOException {
		Path parent = dataFilePath.getParent();

		if (parent != null) Files.createDirectories(parent);

		List<String> lines = new ArrayList<>();
		for (Vehicle vehicle : vehicles) {
			lines.add(serializeVehicle(vehicle));
		}

		Files.write(dataFilePath, lines);
	}

	public List<Vehicle> loadVehicles() throws VehicleDataFileMissingException, VehicleDataFormatException {
		if (!Files.exists(dataFilePath)) throw new VehicleDataFileMissingException("Fisierul " + dataFilePath + " nu exista.");

		List<String> lines;
		try {
			lines = Files.readAllLines(dataFilePath);
		} catch (IOException exception) {
			throw new VehicleDataFormatException("Nu s-a putut citi fisierul de date.", exception);
		}

		List<Vehicle> vehicles = new ArrayList<>();

		int lineNumber = 0;
		for (String rawLine : lines) {
			lineNumber++;
			String line = rawLine.trim();

			if (line.isEmpty()) continue;

			vehicles.add(parseVehicle(line, lineNumber));
		}

		return vehicles;
	}

	private String serializeVehicle(Vehicle vehicle) {
		return String.join(DELIMITER, vehicle.getPersistenceType(), Integer.toString(vehicle.getVehicleNumber()),
				Integer.toString(vehicle.getNumberOfSeats()), vehicle.getRoute(), Double.toString(vehicle.getFare()),
				vehicle.getPersistenceExtraValue());
	}

	private Vehicle parseVehicle(String line, int lineNumber) throws VehicleDataFormatException {
		String[] parts = line.split("\\|", -1);

		if (parts.length != RECORD_SIZE) throw new VehicleDataFormatException("Linia " + lineNumber + " are un format invalid.");

		try {
			String persistenceType = parts[0].trim();
			int vehicleNumber = Integer.parseInt(parts[1].trim());
			int numberOfSeats = Integer.parseInt(parts[2].trim());
			String route = parts[3].trim();
			double fare = Double.parseDouble(parts[4].trim());
			String extra = parts[5].trim();

			switch (persistenceType) {
				case "BUS": {
					return new Bus(vehicleNumber, numberOfSeats, route, fare, extra);
				}
				case "TRAM": {
					return new Tram(vehicleNumber, numberOfSeats, route, fare, Integer.parseInt(extra));
				}
				case "METRO": {
					return new Metro(vehicleNumber, numberOfSeats, route, fare, Integer.parseInt(extra));
				}
				default: {
					throw new VehicleDataFormatException("Linia " + lineNumber + " contine un tip necunoscut: " + persistenceType + ".");
				}
			}
		} catch (NumberFormatException | VehicleValidationException exception) {
			throw new VehicleDataFormatException("Linia " + lineNumber + " nu poate fi interpretata corect.", exception);
		}
	}
}
