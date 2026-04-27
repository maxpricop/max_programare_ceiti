package studiul_individual_2.model;

import studiul_individual_2.exceptions.VehicleValidationException;

/**
 * Base transport vehicle abstraction used by all concrete vehicle types.
 */
public abstract class Vehicle {

	private int vehicleNumber;
	private int numberOfSeats;
	private String route;
	private double fare;

	protected Vehicle() {
		this.vehicleNumber = 1;
		this.numberOfSeats = 1;
		this.route = "Necunoscut";
		this.fare = 1.0;
	}

	protected Vehicle(int vehicleNumber, int numberOfSeats, String route, double fare) throws VehicleValidationException {
		readData(vehicleNumber, numberOfSeats, route, fare);
	}

	public int getVehicleNumber() {
		return vehicleNumber;
	}

	public void setVehicleNumber(int vehicleNumber) throws VehicleValidationException {
		validatePositiveInteger(vehicleNumber, "Numarul vehiculului trebuie sa fie mai mare decat 0.");
		this.vehicleNumber = vehicleNumber;
	}

	public int getNumberOfSeats() {
		return numberOfSeats;
	}

	public void setNumberOfSeats(int numberOfSeats) throws VehicleValidationException {
		validatePositiveInteger(numberOfSeats, "Numarul de locuri trebuie sa fie mai mare decat 0.");
		this.numberOfSeats = numberOfSeats;
	}

	public String getRoute() {
		return route;
	}

	public void setRoute(String route) throws VehicleValidationException {
		validateRoute(route);
		this.route = route.trim();
	}

	public double getFare() {
		return fare;
	}

	public void setFare(double fare) throws VehicleValidationException {
		validatePositiveDouble(fare, "Tariful trebuie sa fie mai mare decat 0.");
		this.fare = fare;
	}

	public String getLineName() {
		return getRoute();
	}

	public void setLineName(String lineName) throws VehicleValidationException {
		setRoute(lineName);
	}

	public int getCapacity() {
		return getNumberOfSeats();
	}

	public void setCapacity(int capacity) throws VehicleValidationException {
		setNumberOfSeats(capacity);
	}

	public boolean isAvailable() {
		return numberOfSeats > 0;
	}

	public double calculateDailyRevenue(int numberOfPassengers) throws VehicleValidationException {
		validateNonNegativeInteger(numberOfPassengers, "Numarul de calatori nu poate fi negativ.");
		return numberOfPassengers * fare;
	}

	public void readData(int vehicleNumber, int numberOfSeats, String route, double fare) throws VehicleValidationException {
		setVehicleNumber(vehicleNumber);
		setNumberOfSeats(numberOfSeats);
		setRoute(route);
		setFare(fare);
	}

	public String displayData() {
		return toString();
	}

	public abstract String getTypeName();

	public abstract String getSpecificDetails();

	public abstract String getPersistenceType();

	public abstract String getPersistenceExtraValue();

	@Override
	public String toString() {
		return "tip=" + getTypeName() + ", numarVehicul=" + vehicleNumber + ", numarLocuri=" + numberOfSeats + ", traseu=" + route
				+ ", tarif=" + fare + ", detalii=" + getSpecificDetails();
	}

	private static void validateRoute(String value) throws VehicleValidationException {
		if (value == null || value.trim().isEmpty()) throw new VehicleValidationException("Traseul este obligatoriu.");

		if (value.contains("|")) throw new VehicleValidationException("Traseul nu poate contine caracterul |.");
	}

	private static void validatePositiveInteger(int value, String message) throws VehicleValidationException {
		if (value <= 0) throw new VehicleValidationException(message);
	}

	private static void validateNonNegativeInteger(int value, String message) throws VehicleValidationException {
		if (value < 0) throw new VehicleValidationException(message);
	}

	private static void validatePositiveDouble(double value, String message) throws VehicleValidationException {
		if (value <= 0) throw new VehicleValidationException(message);
	}
}
