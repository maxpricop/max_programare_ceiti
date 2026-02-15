package lectia6.data;

import java.util.regex.Pattern;

public final class Constants {
	public static final String USERS_FILEPATH = "data/users.txt";

	public static final int USERNAME_MIN_LENGTH = 3;
	public static final int USERNAME_MAX_LENGTH = 20;
	public static final Pattern USERNAME_PATTERN = Pattern.compile("^[A-Za-z0-9._-]+$");

	public static final int PASSWORD_MIN_LENGTH = 8;
	public static final int PASSWORD_MAX_LENGTH = 64;
	public static final Pattern PASSWORD_PATTERN = Pattern.compile("^[\\x21-\\x7E]+$");
}
