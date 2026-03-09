package lectia8.services;

import lectia8.model.Utilizator;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class AuthService {
	private static final AuthService INSTANCE = new AuthService();
	private final List<Utilizator> utilizatori = new ArrayList<>();
	private Utilizator utilizatorCurent;

	private static final int MAX_FAILED = 3;

	private AuthService() {
		// No default admin created per assignment requirements
	}

	public static AuthService getInstance() {
		return INSTANCE;
	}

	public synchronized Utilizator findByUsername(String username) {
		if (username == null) return null;
		for (Utilizator u : utilizatori) {
			if (username.equals(u.getUsername())) return u;
		}
		return null;
	}

	public synchronized List<Utilizator> listUsers() {
		return Collections.unmodifiableList(new ArrayList<>(utilizatori));
	}

	public synchronized void register(String username, String password, String email) {
		if (findByUsername(username) != null) throw new IllegalArgumentException("Username deja folosit");
		Utilizator u = new Utilizator(username, password, email);
		utilizatori.add(u);
	}

	public synchronized boolean login(String username, String password) {
		Utilizator u = findByUsername(username);
		if (u == null) return false;
		if (u.isLocked()) return false;
		if (u.checkPassword(password)) {
			u.setFailedAttempts(0);
			utilizatorCurent = u;
			return true;
		} else {
			u.incrementFailedAttempts();
			if (u.getFailedAttempts() >= MAX_FAILED) u.setLocked(true);
			return false;
		}
	}

	public Utilizator getCurrentUser() {
		return utilizatorCurent;
	}

	public void logout() {
		utilizatorCurent = null;
	}

	public synchronized void resetFailedAttempts(String username) {
		Utilizator u = findByUsername(username);
		if (u != null) u.setFailedAttempts(0);
	}

	public synchronized void lockUser(String username) {
		Utilizator u = findByUsername(username);
		if (u != null) u.setLocked(true);
	}

	public synchronized void unlockUser(String username) {
		Utilizator u = findByUsername(username);
		if (u != null) { u.setLocked(false); u.setFailedAttempts(0); }
	}

	public synchronized void deleteUser(String username) {
		Utilizator u = findByUsername(username);
		if (u != null) utilizatori.remove(u);
	}

	public synchronized void changePassword(String username, String newPassword) {
		Utilizator u = findByUsername(username);
		if (u == null) throw new IllegalArgumentException("Utilizator inexistent");
		u.setPassword(newPassword);
	}
}
