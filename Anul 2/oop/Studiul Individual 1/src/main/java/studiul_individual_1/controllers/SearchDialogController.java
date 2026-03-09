package studiul_individual_1.controllers;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.Window;

import java.util.Optional;

public class SearchDialogController {

	@FXML
	private Label promptLabel;
	@FXML
	private TextField inputField;
	private String result = null;

	@FXML
	private void onSearch() {
		result = inputField.getText().trim();
		inputField.getScene().getWindow().hide();
	}

	@FXML
	private void onCancel() {
		inputField.getScene().getWindow().hide();
	}

	public static Optional<String> show(Window owner, String title, String prompt) {
		try {
			FXMLLoader loader = new FXMLLoader(SearchDialogController.class.getResource("/studiul_individual_1/gui/search_dialog.fxml"));
			Parent root = loader.load();
			SearchDialogController ctrl = loader.getController();
			ctrl.promptLabel.setText(prompt);

			Stage stage = new Stage();
			stage.initModality(Modality.APPLICATION_MODAL);
			stage.initOwner(owner);
			stage.setTitle(title);
			stage.setScene(new Scene(root));
			stage.setResizable(false);
			stage.showAndWait();

			return Optional.ofNullable(ctrl.result);
		} catch (Exception e) {
			throw new RuntimeException("Failed to load search_dialog.fxml", e);
		}
	}
}
