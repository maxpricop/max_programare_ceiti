package studiul_individual_2.exceptions;

/**
 * Raised when a load operation is requested but the data file is missing.
 */
public class VehicleDataFileMissingException extends Exception {

	public VehicleDataFileMissingException(String message) {
		super(message);
	}

	public VehicleDataFileMissingException(String message, Throwable cause) {
		super(message, cause);
	}
}
