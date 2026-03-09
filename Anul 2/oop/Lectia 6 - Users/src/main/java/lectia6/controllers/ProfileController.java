package lectia6.controllers;

import java.io.IOException;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.control.Label;
import javafx.scene.control.Button;
import javafx.scene.Scene;
import javafx.stage.Modality;
import javafx.stage.Stage;

import lectia6.model.User;
import lectia6.storage.UserStore;

public class ProfileController {
	@FXML
	private Label usernameLabel;

	@FXML
	private Label passwordHashLabel;

	@FXML
	private Label messageLabel;

	@FXML
	private Button changeUsernameButton;

	@FXML
	private Button changePasswordButton;

	@FXML
	private Button logoutButton;

	private UserStore users;
	private User user;
	private PrimaryController primaryController;

	public void setUsers(UserStore store) {
		this.users = store;
	}

	public void setUser(User user) {
		this.user = user;
		refreshView();
	}

	public void setPrimaryController(PrimaryController newPrimaryController) {
		this.primaryController = newPrimaryController;
	}

	private void refreshView() {
		if (this.user == null) return;

		this.usernameLabel.setText(this.user.getUsername());
		this.passwordHashLabel.setText(this.user.getPasswordHash());
		this.messageLabel.setText("");
	}

	@FXML
	private void handleLogout() {
		if (this.primaryController == null) return;
		this.primaryController.showLogin();
	}

	@FXML
	private void handleChangeUsername() {
		if (this.users == null) {
			this.messageLabel.setText("Users file not found.");

			return;
		}

		if (this.user == null) {
			this.messageLabel.setText("User not found");

			return;
		}

		try {
			FXMLLoader loader = new FXMLLoader(getClass().getResource("/lectia6/change_username.fxml"));
			Parent root = loader.load();

			ChangeUsernameController ctrl = loader.getController();
			ctrl.init(this.users, this.user.getUsername());

			Stage dialog = new Stage();
			dialog.initOwner(usernameLabel.getScene().getWindow());
			dialog.initModality(Modality.APPLICATION_MODAL);
			dialog.setTitle("Change username");
			dialog.setScene(new Scene(root));
			dialog.showAndWait();

			if (ctrl.isSuccess()) {
				this.messageLabel.setText("Username changed. You have been logged out.");
				if (this.primaryController != null) this.primaryController.showLogin();
			}
		} catch (IOException e) {
			this.messageLabel.setText("Failed to open dialog.");
			e.printStackTrace();
		}
	}

	@FXML
	private void handleChangePassword() {
		if (this.users == null) {
			this.messageLabel.setText("Users file not found.");

			return;
		}

		if (this.user == null) {
			this.messageLabel.setText("User not found");

			return;
		}

		try {
			FXMLLoader loader = new FXMLLoader(getClass().getResource("/lectia6/change_password.fxml"));
			Parent root = loader.load();

			ChangePasswordController ctrl = loader.getController();
			ctrl.init(this.users, this.user.getUsername());

			Stage dialog = new Stage();
			dialog.initOwner(usernameLabel.getScene().getWindow());
			dialog.initModality(Modality.APPLICATION_MODAL);
			dialog.setTitle("Change password");
			dialog.setScene(new Scene(root));
			dialog.showAndWait();

			if (ctrl.isSuccess()) {
				this.messageLabel.setText("Password changed. You have been logged out.");
				if (this.primaryController != null) this.primaryController.showLogin();
			}
		} catch (IOException e) {
			this.messageLabel.setText("Failed to open dialog.");
			e.printStackTrace();
		}
	}
}
