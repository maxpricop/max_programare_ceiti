package studiul_individual_2.model;

import java.util.Set;
import studiul_individual_2.exceptions.VehicleValidationException;

/**
 * Bus vehicle model.
 */
public class Bus extends Vehicle {

	public static final Set<String> VALID_FUELS = Set.of("diesel", "electric", "hybrid");

	private String fuelType;

	public Bus() {
		super();
		this.fuelType = "diesel";
	}

	public Bus(int vehicleNumber, int numberOfSeats, String route, double fare, String fuelType) throws VehicleValidationException {
		super(vehicleNumber, numberOfSeats, route, fare);
		setFuelType(fuelType);
	}

	public String getFuelType() {
		return fuelType;
	}

	public void setFuelType(String fuelType) throws VehicleValidationException {
		if (fuelType == null || fuelType.trim().isEmpty()) {
			throw new VehicleValidationException("Tipul de combustibil este obligatoriu.");
		}

		String normalized = fuelType.trim().toLowerCase();
		if (!VALID_FUELS.contains(normalized)) {
			throw new VehicleValidationException("Tip combustibil invalid. Folositi: diesel, electric sau hybrid.");
		}

		this.fuelType = normalized;
	}

	public void readData(int vehicleNumber, int numberOfSeats, String route, double fare, String fuelType)
			throws VehicleValidationException {
		super.readData(vehicleNumber, numberOfSeats, route, fare);
		setFuelType(fuelType);
	}

	@Override
	public String displayData() {
		return toString();
	}

	@Override
	public String getTypeName() {
		return "Autobuz";
	}

	@Override
	public String getSpecificDetails() {
		return "Tip combustibil: " + fuelType;
	}

	@Override
	public String getPersistenceType() {
		return "BUS";
	}

	@Override
	public String getPersistenceExtraValue() {
		return fuelType;
	}

	@Override
	public String toString() {
		return super.toString();
	}
}
