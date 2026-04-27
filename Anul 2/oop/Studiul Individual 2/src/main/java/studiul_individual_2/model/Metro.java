package studiul_individual_2.model;

import studiul_individual_2.exceptions.VehicleValidationException;

/**
 * Metro vehicle model.
 */
public class Metro extends Vehicle {

	private int stationCount;

	public Metro() {
		super();
		this.stationCount = 1;
	}

	public Metro(int vehicleNumber, int numberOfSeats, String route, double fare, int stationCount) throws VehicleValidationException {
		super(vehicleNumber, numberOfSeats, route, fare);
		setStationCount(stationCount);
	}

	public int getStationCount() {
		return stationCount;
	}

	public void setStationCount(int stationCount) throws VehicleValidationException {
		if (stationCount <= 0) throw new VehicleValidationException("Numarul de statii trebuie sa fie mai mare decat 0.");
		this.stationCount = stationCount;
	}

	public void readData(int vehicleNumber, int numberOfSeats, String route, double fare, int stationCount)
			throws VehicleValidationException {
		super.readData(vehicleNumber, numberOfSeats, route, fare);
		setStationCount(stationCount);
	}

	@Override
	public String displayData() {
		return toString();
	}

	@Override
	public String getTypeName() {
		return "Metrou";
	}

	@Override
	public String getSpecificDetails() {
		return "Numar statii: " + stationCount;
	}

	@Override
	public String getPersistenceType() {
		return "METRO";
	}

	@Override
	public String getPersistenceExtraValue() {
		return Integer.toString(stationCount);
	}

	@Override
	public String toString() {
		return super.toString();
	}
}
