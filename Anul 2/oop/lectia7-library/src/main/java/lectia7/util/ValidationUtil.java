package lectia7.util;

import java.util.regex.Pattern;

public final class ValidationUtil {
	private static final int MAX_LENGTH = 100;
	private static final Pattern TEXT_PATTERN = Pattern.compile("^[A-Za-z0-9ĂÂÎȘȚăâîșț .,\\-!'\"()]{1,100}$");

	public static void validateTitle(String title) {
		validateText(title, "Title");
	}

	public static void validateAuthor(String author) {
		validateText(author, "Author");
	}

	private static void validateText(String text, String fieldName) {
		if (text == null) throw new IllegalArgumentException(fieldName + " cannot be null.");

		text = text.trim();
		if (text.isEmpty()) throw new IllegalArgumentException(fieldName + " cannot be empty.");
		if (text.length() > MAX_LENGTH) throw new IllegalArgumentException(fieldName + " is too long.");
		if (!TEXT_PATTERN.matcher(text).matches()) throw new IllegalArgumentException(fieldName + " contains invalid characters.");
	}
}
