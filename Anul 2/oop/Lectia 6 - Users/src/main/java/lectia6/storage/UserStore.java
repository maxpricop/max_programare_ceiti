package lectia6.storage;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Optional;

import lectia6.model.User;

public final class UserStore {
	private final Path filePath;
	private final List<String> lines;

	public UserStore(String originalPath) throws IOException {
		this.filePath = Paths.get(originalPath);

		if (!Files.exists(filePath)) throw new IOException("Users file does not exist: " + this.filePath);

		this.lines = new ArrayList<>(Files.readAllLines(this.filePath));
	}

	public List<User> getAllUsers() {
		List<User> users = new ArrayList<>();

		for (String line : lines) {
			Optional<User> possibileUser = parseLine(line);
			if (!possibileUser.isPresent()) continue;

			User newUser = possibileUser.get();
			users.add(newUser);
		}

		return users;
	}

	public Optional<User> getUser(String username) {
		for (String line : lines) {
			Optional<User> possibileUser = parseLine(line);
			if (!possibileUser.isPresent()) continue;

			User user = possibileUser.get();
			String possibileUsername = user.getUsername();
			if (!possibileUsername.equals(username)) continue;

			return Optional.of(user);
		}

		return Optional.empty();
	}

	public void addUser(User newUser) throws IOException {
		Objects.requireNonNull(newUser);

		Optional<User> existingUser = this.getUser(newUser.getUsername());
		if (existingUser.isPresent()) throw new IllegalArgumentException("Username already exists.");

		String newLine = newUser.getUsername() + " " + newUser.getPasswordHash();
		lines.add(newLine);
		saveToFile();
	}

	public void updateUser(String oldUsername, User updatedUser) throws IOException {
		Objects.requireNonNull(oldUsername);
		Objects.requireNonNull(updatedUser);

		if (!oldUsername.equals(updatedUser.getUsername())) {
			Optional<User> existingUserWithUsername = getUser(updatedUser.getUsername());
			if (existingUserWithUsername.isPresent()) throw new IllegalArgumentException("New username is already taken.");
		}

		boolean found = false;
		for (int i = 0; i < lines.size(); i++) {
			Optional<User> possibileUser = parseLine(lines.get(i));
			if (!possibileUser.isPresent()) continue;

			User oldUser = possibileUser.get();
			if (!oldUsername.equals(oldUser.getUsername())) continue;

			lines.set(i, updatedUser.getUsername() + " " + updatedUser.getPasswordHash());

			found = true;
			break;
		}

		if (!found) throw new IllegalArgumentException("User not found.");

		saveToFile();
	}

	public boolean deleteUser(String username) throws IOException {
		boolean removed = false;

		for (int i = 0; i < lines.size(); i++) {
			Optional<User> possibileUser = parseLine(lines.get(i));
			if (!possibileUser.isPresent()) continue;

			User user = possibileUser.get();
			if (!username.equals(user.getUsername())) continue;

			lines.remove(i);
			removed = true;
			break;
		}

		if (removed) saveToFile();
		return removed;
	}

	private Optional<User> parseLine(String line) {
		String trimmedLine = line.trim();
		if (trimmedLine.isEmpty()) return Optional.empty();

		String[] parts = trimmedLine.split(" ", 2);
		if (parts.length < 2) return Optional.empty();

		String username = parts[0];
		String passwordHash = parts[1];

		User newUser = new User(username, passwordHash, true);
		return Optional.of(newUser);
	}

	private void saveToFile() throws IOException {
		Files.write(filePath, lines);
	}
}
