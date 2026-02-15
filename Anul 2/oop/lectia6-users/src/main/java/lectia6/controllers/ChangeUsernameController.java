package lectia6.controllers;

import java.io.IOException;
import java.util.Optional;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;
import lectia6.model.User;
import lectia6.storage.UserStore;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class ChangeUsernameController {
	@FXML
	private TextField newUsernameField;

	@FXML
	private Label messageLabel;

	@FXML
	private Button confirmButton;

	@FXML
	private Button cancelButton;

	private UserStore users;
	private String oldUsername;
	private boolean success = false;

	public void init(UserStore users, String oldUsername) {
		this.users = users;
		this.oldUsername = oldUsername;
	}

	@FXML
	private void handleConfirm() {
		this.messageLabel.setText("");
		String newUsername = this.newUsernameField.getText();

		if (this.users == null || this.oldUsername == null) {
			this.messageLabel.setText("Internal Error");

			return;
		}

		try {
			Optional<User> possibileUser = this.users.getUser(this.oldUsername);
			if (possibileUser.isEmpty()) {
				this.messageLabel.setText("Current user not found.");

				return;
			}

			User user = possibileUser.get();
			user.setUsername(newUsername);

			this.users.updateUser(this.oldUsername, user);
			this.success = true;

			this.newUsernameField.getScene().getWindow().hide();
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
		this.newUsernameField.getScene().getWindow().hide();
	}

	public boolean isSuccess() {
		return this.success;
	}
}
