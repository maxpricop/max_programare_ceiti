package studiul_individual_1.controllers;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.Window;

public class ConfirmDialogController {

	@FXML
	private Label msgLabel;
	private boolean confirmed = false;

	@FXML
	private void onOk() {
		confirmed = true;
		msgLabel.getScene().getWindow().hide();
	}

	@FXML
	private void onCancel() {
		msgLabel.getScene().getWindow().hide();
	}

	public static boolean show(Window owner, String title, String message) {
		try {
			FXMLLoader loader = new FXMLLoader(ConfirmDialogController.class.getResource("/studiul_individual_1/gui/confirm_dialog.fxml"));
			Parent root = loader.load();
			ConfirmDialogController ctrl = loader.getController();
			ctrl.msgLabel.setText(message);

			Stage stage = new Stage();
			stage.initModality(Modality.APPLICATION_MODAL);
			stage.initOwner(owner);
			stage.setTitle(title);
			stage.setScene(new Scene(root));
			stage.setResizable(false);
			stage.showAndWait();

			return ctrl.confirmed;
		} catch (Exception e) {
			throw new RuntimeException("Failed to load confirm_dialog.fxml", e);
		}
	}
}
