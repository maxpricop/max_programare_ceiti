package model;

import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.List;
import java.util.ArrayList;
import java.util.StringTokenizer;

public final class StringWork {
	public static boolean phoneNumberValidation(String phoneNumber) {
		Pattern LOCAL_PATTERN = Pattern.compile("^07\\d{2}-\\d{3}-\\d{3}$");
		Pattern INTERNATIONAL_PATTERN = Pattern.compile("^\\+40 7\\d{2} \\d{3} \\d{3}$");

		boolean matchesLocal = LOCAL_PATTERN.matcher(phoneNumber).matches();
		boolean matchesInternational = INTERNATIONAL_PATTERN.matcher(phoneNumber).matches();

		return matchesLocal || matchesInternational;
	}

	public static List<String> extractEmails(String text) {
		if (text == null) return new ArrayList<>();

		Pattern EMAIL_PATTERN = Pattern.compile("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");

		Matcher matcher = EMAIL_PATTERN.matcher(text);
		List<String> emails = new ArrayList<>();

		while (matcher.find()) {
			emails.add(matcher.group());
		}

		return emails;
	}

	public static String reverseWithStringBuffer(String input) {
		if (input == null) return null;

		StringBuffer sb = new StringBuffer(input);
		return sb.reverse().toString();
	}

	public static String reverseWithStringBuilder(String input) {
		if (input == null) return null;

		StringBuilder sb = new StringBuilder(input);
		return sb.reverse().toString();
	}

	public static String replaceWithStringBuffer(String text, String target, String replacement) {
		if (text == null) return null;
		if (target == null || target.isEmpty()) return text;
		if (replacement == null) replacement = "";

		StringBuffer sb = new StringBuffer(text);
		int idx = sb.indexOf(target);
		while (idx != -1) {
			sb.delete(idx, idx + target.length());
			sb.insert(idx, replacement);
			idx = sb.indexOf(target, idx + replacement.length());
		}

		return sb.toString();
	}

	public static boolean isPalindrome(String input) {
		if (input == null) return false;

		String cleaned = input.replaceAll("\\s+", "").toLowerCase();
		String reversed = new StringBuilder(cleaned).reverse().toString();
		return cleaned.equals(reversed);
	}

	public static List<String> tokenizeWithStringTokenizer(String text) {
		if (text == null) return new ArrayList<>();

		StringTokenizer st = new StringTokenizer(text, " ,.!?");
		List<String> tokens = new ArrayList<>();

		while (st.hasMoreTokens()) {
			tokens.add(st.nextToken());
		}

		return tokens;
	}

	public static boolean isPasswordSecure(String password) {
		if (password == null) return false;

		Pattern SECURE_PASSWORD = Pattern.compile("^(?=.*[A-Z])(?=.*\\d)(?=.*[@#$%^&+=]).{10,}$");
		return SECURE_PASSWORD.matcher(password).matches();
	}

	public static List<String> extractNumbers(String text) {
		if (text == null) return new ArrayList<>();

		Pattern NUM_PATTERN = Pattern.compile("\\b\\d+\\b");
		Matcher matcher = NUM_PATTERN.matcher(text);
		List<String> numbers = new ArrayList<>();

		while (matcher.find()) {
			numbers.add(matcher.group());
		}

		return numbers;
	}

	public static String formatNumberWithGrouping(String number) {
		if (number == null) return null;

		String num = number;
		boolean negative = num.startsWith("-");
		if (negative) num = num.substring(1);

		num = num.replaceAll("[^0-9]", "");
		if (num.isEmpty()) return number;

		StringBuffer sb = new StringBuffer(num);
		int pos = sb.length() - 3;
		while (pos > 0) {
			sb.insert(pos, ',');
			pos -= 3;
		}

		if (negative) sb.insert(0, '-');
		return sb.toString();
	}

	public static String removeSpecialCharacters(String text) {
		if (text == null) return null;
		return text.replaceAll("[^a-zA-Z0-9]", "");
	}
}
