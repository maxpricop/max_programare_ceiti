package lectia6.controllers;

import java.util.Optional;

import javafx.fxml.FXML;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;

import lectia6.model.User;
import lectia6.storage.UserStore;

public class LoginController {
	@FXML
	private TextField usernameField;

	@FXML
	private PasswordField passwordField;

	@FXML
	private Label messageLabel;

	private UserStore users;
	private PrimaryController primaryController;

	public void setUsers(UserStore newUsers) {
		this.users = newUsers;
	}

	public void setPrimaryController(PrimaryController newPrimaryController) {
		this.primaryController = newPrimaryController;
	}

	@FXML
	private void handleLogin() {
		this.messageLabel.setText("");

		String username = this.usernameField.getText();
		String password = this.passwordField.getText();

		if (this.users == null) {
			this.messageLabel.setText("Users file not found.");

			return;
		}

		try {
			Optional<User> possibileUser = this.users.getUser(username);
			if (possibileUser.isEmpty()) {
				this.messageLabel.setText("User does not exist.");

				return;
			}

			User user = possibileUser.get();

			if (!user.verifyPassword(password)) {
				this.messageLabel.setText("Incorrect password.");

				return;
			}

			this.messageLabel.setText("Login successful!");

			if (this.primaryController == null) return;
			this.primaryController.showProfile(user);
		} catch (Exception e) {
			this.messageLabel.setText(e.getMessage());
		}
	}

	@FXML
	private void switchToRegister() {
		if (this.primaryController == null) return;
		this.primaryController.showRegister();
	}
}
