package studiul_individual_2.exceptions;

/**
 * Raised when persisted vehicle data cannot be parsed safely.
 */
public class VehicleDataFormatException extends Exception {

	public VehicleDataFormatException(String message) {
		super(message);
	}

	public VehicleDataFormatException(String message, Throwable cause) {
		super(message, cause);
	}
}
