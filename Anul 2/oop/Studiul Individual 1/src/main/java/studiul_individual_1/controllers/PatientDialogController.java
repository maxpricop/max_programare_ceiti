package studiul_individual_1.controllers;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.Window;
import studiul_individual_1.model.Patient;

import java.util.Optional;

public class PatientDialogController {

	@FXML
	private TextField tfFirstName;
	@FXML
	private TextField tfLastName;
	@FXML
	private TextField tfPatronymic;
	@FXML
	private TextField tfAddress;
	@FXML
	private TextField tfPhone;
	@FXML
	private TextField tfPolicy;
	@FXML
	private TextField tfSection;
	@FXML
	private TextField tfDiagnosis;

	private Patient result = null;

	@FXML
	private void onSave() {
		String fn = tfFirstName.getText().trim();
		String ln = tfLastName.getText().trim();
		if (fn.isBlank() || ln.isBlank()) {
			MessageDialogController.showError(tfFirstName.getScene().getWindow(), "Numele și prenumele sunt obligatorii.");
			return;
		}
		int policy;
		try {
			policy = Integer.parseInt(tfPolicy.getText().trim());
		} catch (NumberFormatException e) {
			MessageDialogController.showError(tfPolicy.getScene().getWindow(), "Număr poliță invalid.");
			return;
		}
		Patient p = new Patient(fn, ln, policy, tfSection.getText().trim());
		p.setPatronymic(tfPatronymic.getText().trim());
		p.setAddress(tfAddress.getText().trim());
		p.setPhone(tfPhone.getText().trim());
		p.setDiagnosis(tfDiagnosis.getText().trim());
		result = p;
		tfFirstName.getScene().getWindow().hide();
	}

	@FXML
	private void onCancel() {
		tfFirstName.getScene().getWindow().hide();
	}

	private void fill(Patient p) {
		tfFirstName.setText(p.getFirstName() != null ? p.getFirstName() : "");
		tfLastName.setText(p.getLastName() != null ? p.getLastName() : "");
		tfPatronymic.setText(p.getPatronymic() != null ? p.getPatronymic() : "");
		tfAddress.setText(p.getAddress() != null ? p.getAddress() : "");
		tfPhone.setText(p.getPhone() != null ? p.getPhone() : "");
		tfPolicy.setText(p.getPolicyNumber() == null ? "" : String.valueOf(p.getPolicyNumber()));
		tfSection.setText(p.getSection() != null ? p.getSection() : "");
		tfDiagnosis.setText(p.getDiagnosis() != null ? p.getDiagnosis() : "");
	}

	public static Optional<Patient> show(Window owner, Patient existing) {
		try {
			FXMLLoader loader = new FXMLLoader(PatientDialogController.class.getResource("/studiul_individual_1/gui/patient_dialog.fxml"));
			Parent root = loader.load();
			PatientDialogController ctrl = loader.getController();
			if (existing != null) ctrl.fill(existing);

			Stage stage = new Stage();
			stage.initModality(Modality.APPLICATION_MODAL);
			stage.initOwner(owner);
			stage.setTitle(existing == null ? "Adaugă pacient" : "Modifică pacient");
			stage.setScene(new Scene(root));
			stage.setResizable(false);
			stage.showAndWait();

			return Optional.ofNullable(ctrl.result);
		} catch (Exception e) {
			throw new RuntimeException("Failed to load patient_dialog.fxml", e);
		}
	}
}
