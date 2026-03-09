package studiul_individual_1.controllers;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.Window;

public class MessageDialogController {

	@FXML
	private Label msgLabel;

	@FXML
	private void onOk() {
		msgLabel.getScene().getWindow().hide();
	}

	public static void show(Window owner, String title, String message) {
		try {
			FXMLLoader loader = new FXMLLoader(MessageDialogController.class.getResource("/studiul_individual_1/gui/message_dialog.fxml"));
			Parent root = loader.load();
			MessageDialogController ctrl = loader.getController();
			ctrl.msgLabel.setText(message != null ? message : "A apărut o eroare necunoscută.");

			Stage stage = new Stage();
			stage.initModality(Modality.APPLICATION_MODAL);
			stage.initOwner(owner);
			stage.setTitle(title);
			stage.setScene(new Scene(root));
			stage.setResizable(false);
			stage.showAndWait();
		} catch (Exception e) {
			throw new RuntimeException("Failed to load message_dialog.fxml", e);
		}
	}

	public static void showError(Window owner, String message) {
		show(owner, "Eroare", message);
	}

	public static void showInfo(Window owner, String message) {
		show(owner, "Informație", message);
	}
}
