package lectia7.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import lectia7.model.Book;
import lectia7.storage.FileBookStore;

public class FindBookController {
	@FXML
	private TextField titleField;

	@FXML
	private Label resultLabel;

	@FXML
	private Label messageLabel;

	private FileBookStore store;
	private PrimaryController primaryController;

	public void setStore(FileBookStore store) {
		this.store = store;
	}

	public void setPrimaryController(PrimaryController pc) {
		this.primaryController = pc;
	}

	@FXML
	private void handleFind() {
		this.messageLabel.setText("");
		this.resultLabel.setText("");

		String title = this.titleField.getText();
		if (title == null || title.trim().isEmpty()) {
			this.messageLabel.setText("Enter a title.");

			return;
		}

		if (this.store == null) {
			this.messageLabel.setText("Books file not available.");

			return;
		}

		Book b = this.store.findBookByTitle(title);
		if (b == null) this.resultLabel.setText("Not found.");
		else this.resultLabel.setText(b.toString());
	}

	@FXML
	private void handleBack() {
		if (this.primaryController != null) this.primaryController.showList();
	}
}
