package lectia7.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import lectia7.model.Book;
import lectia7.storage.FileBookStore;

public class AddBookController {
	@FXML
	private TextField titleField;

	@FXML
	private TextField authorField;

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
	private void handleAdd() {
		messageLabel.setText("");

		String title = this.titleField.getText();
		String author = this.authorField.getText();

		try {
			Book book = new Book(title, author);

			if (this.store == null) {
				this.messageLabel.setText("Books file not available (cannot add).");

				return;
			}

			this.store.addBook(book);
			this.messageLabel.setText("Book added (in memory).");

			this.titleField.clear();
			this.authorField.clear();
		} catch (IllegalArgumentException e) {
			this.messageLabel.setText(e.getMessage());
		} catch (Exception e) {
			this.messageLabel.setText("Error adding book: " + e.getMessage());
		}
	}

	@FXML
	private void handleBack() {
		if (this.primaryController != null) this.primaryController.showList();
	}
}
