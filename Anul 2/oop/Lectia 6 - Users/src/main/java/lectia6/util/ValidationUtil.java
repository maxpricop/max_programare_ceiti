package lectia6.util;

import java.util.regex.Pattern;

import lectia6.data.Constants;

public final class ValidationUtil {
	private static final int USERNAME_MIN_LENGTH = Constants.USERNAME_MIN_LENGTH;
	private static final int USERNAME_MAX_LENGTH = Constants.USERNAME_MAX_LENGTH;
	private static final Pattern USERNAME_PATTERN = Constants.USERNAME_PATTERN;

	private static final int PASSWORD_MIN_LENGTH = Constants.PASSWORD_MIN_LENGTH;
	private static final int PASSWORD_MAX_LENGTH = Constants.PASSWORD_MAX_LENGTH;
	private static final Pattern PASSWORD_PATTERN = Constants.PASSWORD_PATTERN;

	public static void validateUsername(String username) {
		if (username == null) throw new IllegalArgumentException("Username cannot be null.");

		if (username.length() < USERNAME_MIN_LENGTH)
			throw new IllegalArgumentException("Username must be at least " + USERNAME_MIN_LENGTH + " characters long.");

		if (username.length() > USERNAME_MAX_LENGTH)
			throw new IllegalArgumentException("Username must be at most " + USERNAME_MAX_LENGTH + " characters long.");

		if (!USERNAME_PATTERN.matcher(username).matches())
			throw new IllegalArgumentException("Username can only contain Latin letters, numbers, '.', '_', and '-'.");
	}

	public static void validatePassword(String password) {
		if (password == null) throw new IllegalArgumentException("Password cannot be null.");

		if (password.length() < PASSWORD_MIN_LENGTH)
			throw new IllegalArgumentException("Password must be at least " + PASSWORD_MIN_LENGTH + " characters long.");

		if (password.length() > PASSWORD_MAX_LENGTH)
			throw new IllegalArgumentException("Password must be at most " + PASSWORD_MAX_LENGTH + " characters long.");

		if (!PASSWORD_PATTERN.matcher(password).matches()) throw new IllegalArgumentException("Password contains invalid characters.");
	}
}
