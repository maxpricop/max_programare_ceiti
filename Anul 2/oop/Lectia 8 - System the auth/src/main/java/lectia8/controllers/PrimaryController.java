package lectia8.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import lectia8.Main;
import lectia8.services.AuthService;

import java.io.IOException;

public class PrimaryController {
	@FXML
	private TextField tfNume;
	@FXML
	private TextField tfEmail;
	@FXML
	private PasswordField pfParola;
	@FXML
	private Label lblMesaj;
	@FXML
	private Button btnAutentificare;
	@FXML
	private Button btnInregistrare;

	private final AuthService auth = AuthService.getInstance();

	@FXML
	private void initialize() {
		lblMesaj.setText("");
	}

	@FXML
	private void autentificare() throws IOException {
		String nume = tfNume.getText() == null ? "" : tfNume.getText().trim();
		String parola = pfParola.getText() == null ? "" : pfParola.getText();
		if (nume.isEmpty() || parola.isEmpty()) { lblMesaj.setText("Introduceți nume utilizator și parolă."); return; }
		boolean ok = auth.login(nume, parola);
		if (ok) {
			Main.setRoot("secondary");
		} else {
			var u = auth.findByUsername(nume);
			if (u != null && u.isLocked()) {
				lblMesaj.setText("Cont blocat. Contactați administratorul.");
			} else {
				lblMesaj.setText("Autentificare eșuată. Verificați datele.");
			}
		}
	}

	@FXML
	private void inregistrare() {
		String nume = tfNume.getText() == null ? "" : tfNume.getText().trim();
		String parola = pfParola.getText() == null ? "" : pfParola.getText();
		String email = tfEmail.getText() == null ? "" : tfEmail.getText().trim();
		if (nume.isEmpty() || parola.isEmpty() || email.isEmpty()) {
			lblMesaj.setText("Completați username, email și parolă pentru înregistrare.");
			return;
		}
		try {
			auth.register(nume, parola, email);
			lblMesaj.setText("Înregistrare reușită. Puteți autentifica.");
		} catch (IllegalArgumentException ex) {
			lblMesaj.setText("Eroare: " + ex.getMessage());
		}
	}
}
