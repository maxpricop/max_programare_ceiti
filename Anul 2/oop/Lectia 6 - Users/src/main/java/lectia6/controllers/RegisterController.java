package lectia6.controllers;

import java.io.IOException;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;

import lectia6.model.User;
import lectia6.storage.UserStore;

public class RegisterController {
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
	private void handleRegister() {
		this.messageLabel.setText("");

		String username = this.usernameField.getText();
		String password = this.passwordField.getText();

		if (this.users == null) {
			this.messageLabel.setText("Users file not found.");

			return;
		}

		try {
			User newUser = new User(username, password);
			this.users.addUser(newUser);

			this.messageLabel.setText("Registration successful!");

			if (this.primaryController == null) return;
			this.primaryController.showProfile(newUser);
		} catch (IllegalArgumentException e) {
			this.messageLabel.setText(e.getMessage());
		} catch (IOException e) {
			this.messageLabel.setText("Users file not found");
		}
	}

	@FXML
	private void switchToLogin() {
		if (this.primaryController == null) return;
		this.primaryController.showLogin();
	}
}
