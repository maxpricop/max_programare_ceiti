package lectia7.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import lectia7.storage.FileBookStore;

public class DeleteBookController {
	@FXML
	private Label confirmLabel;

	@FXML
	private Label messageLabel;

	@FXML
	private Button confirmButton;

	@FXML
	private Button cancelButton;

	private FileBookStore store;
	private String title;
	private boolean success = false;

	public void init(FileBookStore store, String title) {
		this.store = store;
		this.title = title;

		this.confirmLabel.setText("Delete book: \"" + title + "\"?");
		this.messageLabel.setText("");
	}

	@FXML
	private void handleConfirm() {
		if (this.store == null || this.title == null) {
			this.messageLabel.setText("Internal error.");

			return;
		}

		boolean removed = this.store.deleteBookByTitle(title);
		if (!removed) this.messageLabel.setText("Book not found (already removed?).");

		this.success = true;
		this.confirmLabel.getScene().getWindow().hide();

	}

	@FXML
	private void handleCancel() {
		this.confirmLabel.getScene().getWindow().hide();
	}

	public boolean isSuccess() {
		return this.success;
	}
}
