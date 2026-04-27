package studiul_individual_2.model;

import studiul_individual_2.exceptions.VehicleValidationException;

/**
 * Tram vehicle model.
 */
public class Tram extends Vehicle {

	private int wagonCount;

	public Tram() {
		super();
		this.wagonCount = 1;
	}

	public Tram(int vehicleNumber, int numberOfSeats, String route, double fare, int wagonCount) throws VehicleValidationException {
		super(vehicleNumber, numberOfSeats, route, fare);
		setWagonCount(wagonCount);
	}

	public int getWagonCount() {
		return wagonCount;
	}

	public void setWagonCount(int wagonCount) throws VehicleValidationException {
		if (wagonCount <= 0) throw new VehicleValidationException("Numarul de vagoane trebuie sa fie mai mare decat 0.");
		this.wagonCount = wagonCount;
	}

	public void readData(int vehicleNumber, int numberOfSeats, String route, double fare, int wagonCount)
			throws VehicleValidationException {
		super.readData(vehicleNumber, numberOfSeats, route, fare);
		setWagonCount(wagonCount);
	}

	@Override
	public String displayData() {
		return toString();
	}

	@Override
	public String getTypeName() {
		return "Tramvai";
	}

	@Override
	public String getSpecificDetails() {
		return "Numar vagoane: " + wagonCount;
	}

	@Override
	public String getPersistenceType() {
		return "TRAM";
	}

	@Override
	public String getPersistenceExtraValue() {
		return Integer.toString(wagonCount);
	}

	@Override
	public String toString() {
		return super.toString();
	}
}
