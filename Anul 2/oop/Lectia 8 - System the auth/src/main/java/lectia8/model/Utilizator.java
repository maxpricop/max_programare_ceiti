package lectia8.model;

import java.util.Objects;
import java.util.regex.Pattern;

public class Utilizator {
	private String username;
	private int passwordHash; // mandated as int by the assignment
	private String email;
	private int failedAttempts;
	private boolean locked;

	private static final Pattern EMAIL_RE = Pattern.compile("^[^@\\s]+@[^@\\s]+\\.[^@\\s]+$");

	public Utilizator(String username, String password, String email) {
		setUsername(username);
		setPassword(password);
		setEmail(email);
		this.failedAttempts = 0;
		this.locked = false;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		if (username == null || username.isBlank()) throw new IllegalArgumentException("Username invalid");
		if (username.length() < 3 || username.length() > 20)
			throw new IllegalArgumentException("Username trebuie să aibă între 3 și 20 caractere.");
		this.username = username;
	}

	public int getPasswordHash() {
		return passwordHash;
	}

	// store password as int hash (assignment requirement)
	public void setPassword(String password) {
		if (!isValidPassword(password)) throw new IllegalArgumentException("Parolă invalidă: minim 6 caractere, include litere și cifre.");
		this.passwordHash = computeHash(password);
	}

	public boolean checkPassword(String password) {
		return computeHash(password) == this.passwordHash;
	}

	private int computeHash(String password) {
		return password == null ? 0 : password.hashCode();
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		if (email == null || email.isBlank() || !EMAIL_RE.matcher(email).matches()) throw new IllegalArgumentException("Email invalid");
		this.email = email;
	}

	public int getFailedAttempts() {
		return failedAttempts;
	}

	public void setFailedAttempts(int failedAttempts) {
		this.failedAttempts = Math.max(0, failedAttempts);
	}

	public void incrementFailedAttempts() {
		this.failedAttempts++;
	}

	public boolean isLocked() {
		return locked;
	}

	public void setLocked(boolean locked) {
		this.locked = locked;
	}

	public static boolean isValidPassword(String password) {
		if (password == null) return false;
		if (password.length() < 6) return false;
		boolean hasDigit = false, hasLetter = false;
		for (char c : password.toCharArray()) {
			if (Character.isDigit(c)) hasDigit = true;
			if (Character.isLetter(c)) hasLetter = true;
		}
		return hasDigit && hasLetter;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;
		Utilizator that = (Utilizator) o;
		return Objects.equals(username, that.username);
	}

	@Override
	public int hashCode() {
		return Objects.hash(username);
	}
}
