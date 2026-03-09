package studiul_individual_1.controllers;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.Window;

import java.util.Optional;

public class SearchRangeDialogController {

	@FXML
	private TextField tfMin;
	@FXML
	private TextField tfMax;
	private int[] result = null;

	@FXML
	private void onSearch() {
		try {
			int min = Integer.parseInt(tfMin.getText().trim());
			int max = Integer.parseInt(tfMax.getText().trim());
			result = new int[] { min, max };
			tfMin.getScene().getWindow().hide();
		} catch (NumberFormatException e) {
			MessageDialogController.showError(tfMin.getScene().getWindow(), "Numerele de poliță introduse sunt invalide.");
		}
	}

	@FXML
	private void onCancel() {
		tfMin.getScene().getWindow().hide();
	}

	public static Optional<int[]> show(Window owner) {
		try {
			FXMLLoader loader = new FXMLLoader(
					SearchRangeDialogController.class.getResource("/studiul_individual_1/gui/search_range_dialog.fxml"));
			Parent root = loader.load();
			SearchRangeDialogController ctrl = loader.getController();

			Stage stage = new Stage();
			stage.initModality(Modality.APPLICATION_MODAL);
			stage.initOwner(owner);
			stage.setTitle("Caută interval polițe");
			stage.setScene(new Scene(root));
			stage.setResizable(false);
			stage.showAndWait();

			return Optional.ofNullable(ctrl.result);
		} catch (Exception e) {
			throw new RuntimeException("Failed to load search_range_dialog.fxml", e);
		}
	}
}
