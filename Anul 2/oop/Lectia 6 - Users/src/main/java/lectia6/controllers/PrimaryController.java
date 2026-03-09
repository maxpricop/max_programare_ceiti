package lectia6.controllers;

import java.io.IOException;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;

import lectia6.data.Constants;
import lectia6.model.User;
import lectia6.storage.UserStore;

public class PrimaryController {
	@FXML
	private StackPane contentPane;

	private UserStore users;
	private static final String USERS_FILEPATH = Constants.USERS_FILEPATH;

	@FXML
	public void initialize() {
		this.contentPane.sceneProperty().addListener(new ChangeListener<Scene>() {
			@Override
			public void changed(ObservableValue<? extends Scene> obs, Scene oldScene, Scene newScene) {
				if (newScene != null) newScene.getRoot().setUserData(PrimaryController.this);
			}
		});

		try {
			this.users = new UserStore(USERS_FILEPATH);
		} catch (IOException e) {
			// users stays null — login/register controllers will show errors when trying to use it
			System.err.println("Warning: users file not available: " + e.getMessage());
			this.users = null;
		}

		showLogin();
	}

	public void showLogin() {
		loadView("/lectia6/login.fxml");
	}

	public void showRegister() {
		loadView("/lectia6/register.fxml");
	}

	public void showProfile(User user) {
		try {
			FXMLLoader loader = new FXMLLoader(getClass().getResource("/lectia6/secondary.fxml"));
			Parent view = loader.load();

			Object controller = loader.getController();
			if (controller instanceof ProfileController) {
				ProfileController pc = (ProfileController) controller;
				pc.setUsers(this.users);
				pc.setUser(user);
				pc.setPrimaryController(this);
			}

			this.contentPane.getChildren().setAll(view);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void loadView(String fxmlPath) {
		try {
			FXMLLoader loader = new FXMLLoader(getClass().getResource(fxmlPath));
			Parent view = loader.load();

			Object controller = loader.getController();
			if (controller instanceof LoginController) {
				((LoginController) controller).setUsers(this.users);
				((LoginController) controller).setPrimaryController(this);
			} else if (controller instanceof RegisterController) {
				((RegisterController) controller).setUsers(this.users);
				((RegisterController) controller).setPrimaryController(this);
			}

			this.contentPane.getChildren().setAll(view);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public UserStore getUsers() {
		return users;
	}
}
