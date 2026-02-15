package lectia6.model;

import lectia6.util.HashUtil;
import lectia6.util.ValidationUtil;

public class User {
	private String username;
	private String passwordHash;

	public User(String originalUsername, String originalPassword) {
		ValidationUtil.validateUsername(originalUsername);
		ValidationUtil.validatePassword(originalPassword);

		this.username = originalUsername;
		this.passwordHash = HashUtil.hashPassword(originalPassword);
	}

	public User(String originalUsername, String originalPasswordHash, boolean alreadyHashed) {
		String finalUsername = originalUsername;
		String finalPasswordHash = originalPasswordHash;

		if (!alreadyHashed) {
			ValidationUtil.validateUsername(originalUsername);
			ValidationUtil.validatePassword(originalPasswordHash);

			finalUsername = originalUsername;
			finalPasswordHash = HashUtil.hashPassword(originalPasswordHash);
		}

		this.username = finalUsername;
		this.passwordHash = finalPasswordHash;
	}

	public String getUsername() {
		return this.username;
	}

	public String getPasswordHash() {
		return this.passwordHash;
	}

	public void setUsername(String newUsername) {
		ValidationUtil.validateUsername(newUsername);
		this.username = newUsername;
	}

	public void setPassword(String newPassword) {
		ValidationUtil.validatePassword(newPassword);
		this.passwordHash = HashUtil.hashPassword(newPassword);
	}

	public boolean verifyPassword(String enteredPassword) {
		String enteredHash = HashUtil.hashPassword(enteredPassword);
		return this.passwordHash.equals(enteredHash);
	}
}
