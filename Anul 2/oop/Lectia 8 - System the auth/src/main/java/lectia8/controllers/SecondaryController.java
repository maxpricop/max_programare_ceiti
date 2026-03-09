package lectia8.controllers;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import lectia8.model.Utilizator;
import lectia8.services.AuthService;
import java.io.IOException;
import java.util.List;
import java.util.stream.Collectors;
import lectia8.Main;

public class SecondaryController {
	@FXML
	private Label lblSalut;
	@FXML
	private ListView<String> lvUsers;
	@FXML
	private Label lblDetails;
	@FXML
	private TextField tfNewPassword;
	@FXML
	private Label lblMesajSec;

	private final AuthService auth = AuthService.getInstance();

	@FXML
	private void initialize() {
		var u = auth.getCurrentUser();
		if (u != null) {
			lblSalut.setText("Bine ai venit, " + u.getUsername() + "!");
		} else {
			lblSalut.setText("Nicio sesiune activă.");
		}
		refreshUsers();
	}

	@FXML
	private void deconectare() throws IOException {
		auth.logout();
		Main.setRoot("primary");
	}

	@FXML
	private void refreshUsers() {
		List<Utilizator> users = auth.listUsers();
		lvUsers.setItems(FXCollections.observableArrayList(users.stream().map(Utilizator::getUsername).collect(Collectors.toList())));
		lblMesajSec.setText("");
		lblDetails.setText("");
	}

	@FXML
	private void showDetails() {
		String sel = lvUsers.getSelectionModel().getSelectedItem();
		if (sel == null) { lblMesajSec.setText("Selectați un utilizator."); return; }
		Utilizator u = auth.findByUsername(sel);
		if (u == null) { lblMesajSec.setText("Utilizator inexistent."); return; }
		lblDetails.setText("Username: " + u.getUsername() + "\nEmail: " + u.getEmail() + "\nÎncercări eșuate: " + u.getFailedAttempts()
				+ "\nBlocare: " + (u.isLocked() ? "DA" : "NU"));
	}

	@FXML
	private void lockSelected() {
		String sel = lvUsers.getSelectionModel().getSelectedItem();
		if (sel == null) { lblMesajSec.setText("Selectați un utilizator."); return; }
		auth.lockUser(sel);
		lblMesajSec.setText("Utilizator blocat.");
		refreshUsers();
	}

	@FXML
	private void unlockSelected() {
		String sel = lvUsers.getSelectionModel().getSelectedItem();
		if (sel == null) { lblMesajSec.setText("Selectați un utilizator."); return; }
		auth.unlockUser(sel);
		lblMesajSec.setText("Utilizator deblocat.");
		refreshUsers();
	}

	@FXML
	private void resetAttempts() {
		String sel = lvUsers.getSelectionModel().getSelectedItem();
		if (sel == null) { lblMesajSec.setText("Selectați un utilizator."); return; }
		auth.resetFailedAttempts(sel);
		lblMesajSec.setText("Încercări resetate.");
		showDetails();
	}

	@FXML
	private void deleteSelected() {
		String sel = lvUsers.getSelectionModel().getSelectedItem();
		if (sel == null) { lblMesajSec.setText("Selectați un utilizator."); return; }
		auth.deleteUser(sel);
		lblMesajSec.setText("Utilizator șters.");
		refreshUsers();
	}

	@FXML
	private void changePasswordSelected() {
		String sel = lvUsers.getSelectionModel().getSelectedItem();
		String np = tfNewPassword.getText() == null ? "" : tfNewPassword.getText();
		if (sel == null) { lblMesajSec.setText("Selectați un utilizator."); return; }
		if (np.isEmpty()) { lblMesajSec.setText("Introduceți o parolă nouă."); return; }
		try {
			auth.changePassword(sel, np);
			lblMesajSec.setText("Parolă actualizată.");
			tfNewPassword.clear();
		} catch (IllegalArgumentException ex) {
			lblMesajSec.setText("Eroare: " + ex.getMessage());
		}
	}
}
