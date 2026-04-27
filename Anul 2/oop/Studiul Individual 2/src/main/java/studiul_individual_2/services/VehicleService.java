package studiul_individual_2.services;

import studiul_individual_2.exceptions.VehicleDataFileMissingException;
import studiul_individual_2.exceptions.VehicleDataFormatException;
import studiul_individual_2.exceptions.VehicleValidationException;
import studiul_individual_2.model.Vehicle;

import java.io.IOException;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

/**
 * Handles in-memory state and persistence for transport vehicles.
 */
public class VehicleService {

	private final List<Vehicle> vehicles = new ArrayList<>();
	private final VehicleFileService vehicleFileService;

	public VehicleService(Path dataFilePath) {
		this(new VehicleFileService(dataFilePath));
	}

	public VehicleService(VehicleFileService vehicleFileService) {
		this.vehicleFileService = Objects.requireNonNull(vehicleFileService, "Vehicle file service cannot be null.");
	}

	public void addVehicle(Vehicle vehicle) {
		vehicles.add(Objects.requireNonNull(vehicle, "Vehicle cannot be null."));
	}

	public List<Vehicle> getAllVehicles() {
		return List.copyOf(vehicles);
	}

	public List<Vehicle> getAvailableVehicles() {
		return vehicles.stream().filter(Vehicle::isAvailable).collect(Collectors.toList());
	}

	public double calculateRevenueFor(Vehicle vehicle, int numberOfPassengers) throws VehicleValidationException {
		return Objects.requireNonNull(vehicle, "Vehicle cannot be null.").calculateDailyRevenue(numberOfPassengers);
	}

	public double calculateTotalDailyRevenue(List<Integer> passengersPerVehicle) throws VehicleValidationException {
		Objects.requireNonNull(passengersPerVehicle, "Passengers list cannot be null.");

		if (passengersPerVehicle.size() != vehicles.size()) {
			throw new VehicleValidationException("Numarul de valori pentru calatori trebuie sa corespunda cu numarul de vehicule.");
		}

		double totalRevenue = 0.0;
		for (int index = 0; index < vehicles.size(); index++) {
			totalRevenue += vehicles.get(index).calculateDailyRevenue(passengersPerVehicle.get(index));
		}

		return totalRevenue;
	}

	public Path getDataFilePath() {
		return vehicleFileService.getDataFilePath();
	}

	public void saveVehicles() throws IOException {
		vehicleFileService.saveVehicles(vehicles);
	}

	public void loadVehicles() throws VehicleDataFileMissingException, VehicleDataFormatException {
		vehicles.clear();
		vehicles.addAll(vehicleFileService.loadVehicles());
	}
}
