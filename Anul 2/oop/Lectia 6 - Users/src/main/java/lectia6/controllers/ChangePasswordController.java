package lectia6.controllers;

import java.io.IOException;
import java.util.Optional;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import lectia6.model.User;
import lectia6.storage.UserStore;

public class ChangePasswordController {
	@FXML
	private TextField newPasswordField;

	@FXML
	private TextField confirmPasswordField;

	@FXML
	private Label messageLabel;

	@FXML
	private Button confirmButton;

	@FXML
	private Button cancelButton;

	private UserStore users;
	private String username;
	private boolean success = false;

	public void init(UserStore users, String username) {
		this.users = users;
		this.username = username;
	}

	@FXML
	private void handleConfirm() {
		this.messageLabel.setText("");

		if (this.users == null || this.username == null) {
			this.messageLabel.setText("Internal Error");

			return;
		}

		String p1 = newPasswordField.getText();
		String p2 = confirmPasswordField.getText();

		if (!p1.equals(p2)) {
			this.messageLabel.setText("Password do not match");

			return;
		}

		try {
			Optional<User> possibileUser = this.users.getUser(this.username);
			if (possibileUser.isEmpty()) {
				this.messageLabel.setText("Current user not found.");

				return;
			}

			User user = possibileUser.get();
			user.setPassword(p1);

			this.users.updateUser(this.username, user);
			this.success = true;

			this.newPasswordField.getScene().getWindow().hide();
		} catch (IllegalArgumentException e) {
			this.messageLabel.setText(e.getMessage());
		} catch (IOException e) {
			this.messageLabel.setText("Error updating the users file");
		} catch (Exception e) {
			this.messageLabel.setText(e.getMessage());
		}
	}

	@FXML
	private void handleCancel() {
		this.newPasswordField.getScene().getWindow().hide();
	}

	public boolean isSuccess() {
		return this.success;
	}
}
