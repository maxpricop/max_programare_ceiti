package studiul_individual_2.exceptions;

/**
 * Raised when user-provided vehicle data does not satisfy domain rules.
 */
public class VehicleValidationException extends Exception {

	public VehicleValidationException(String message) {
		super(message);
	}

	public VehicleValidationException(String message, Throwable cause) {
		super(message, cause);
	}
}
