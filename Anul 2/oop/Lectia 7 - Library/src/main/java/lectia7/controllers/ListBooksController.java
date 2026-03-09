package lectia7.controllers;

import java.io.IOException;
import java.util.List;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Modality;
import javafx.stage.Stage;

import lectia7.model.Book;
import lectia7.storage.FileBookStore;

public class ListBooksController {
	@FXML
	private TableView<Book> tableView;

	@FXML
	private TableColumn<Book, String> titleColumn;

	@FXML
	private TableColumn<Book, String> authorColumn;

	@FXML
	private Button addButton;

	@FXML
	private Button findButton;

	@FXML
	private Button deleteButton;

	@FXML
	private Button saveButton;

	@FXML
	private Button refreshButton;

	@FXML
	private Label messageLabel;

	private FileBookStore store;
	private PrimaryController primaryController;

	public void setStore(FileBookStore store) {
		this.store = store;
		this.initializeTable();
		this.refresh();
	}

	public void setPrimaryController(PrimaryController pc) {
		this.primaryController = pc;
	}

	@FXML
	private void initialize() {
		this.titleColumn.setCellValueFactory(new PropertyValueFactory<>("title"));
		this.authorColumn.setCellValueFactory(new PropertyValueFactory<>("author"));
	}

	private void initializeTable() {
		this.titleColumn.setCellValueFactory(new PropertyValueFactory<>("title"));
		this.authorColumn.setCellValueFactory(new PropertyValueFactory<>("author"));
	}

	@FXML
	private void handleAdd() {
		if (this.primaryController != null) this.primaryController.showAdd();
	}

	@FXML
	private void handleFind() {
		if (this.primaryController != null) this.primaryController.showFind();
	}

	@FXML
	private void handleDelete() {
		Book selected = this.tableView.getSelectionModel().getSelectedItem();
		if (selected == null) {
			this.messageLabel.setText("No book selected.");

			return;
		}

		try {
			FXMLLoader loader = new FXMLLoader(getClass().getResource("/lectia7/confirm_delete.fxml"));
			Parent root = loader.load();
			DeleteBookController ctrl = loader.getController();
			ctrl.init(this.store, selected.getTitle());

			Stage dialog = new Stage();
			dialog.initOwner(this.tableView.getScene().getWindow());
			dialog.initModality(Modality.APPLICATION_MODAL);
			dialog.setTitle("Confirm delete");
			dialog.setScene(new Scene(root));
			dialog.showAndWait();

			if (ctrl.isSuccess()) {
				this.messageLabel.setText("Book deleted.");

				this.refresh();
			}
		} catch (IOException e) {
			this.messageLabel.setText("Failed to open confirm dialog.");
			e.printStackTrace();
		}
	}

	@FXML
	private void handleSave() {
		if (store == null) {
			this.messageLabel.setText("Books file not available (cannot save).");

			return;
		}
		try {
			this.store.save();
			this.messageLabel.setText("Saved to disk.");
		} catch (IOException e) {
			this.messageLabel.setText("Error saving: " + e.getMessage());
			e.printStackTrace();
		}
	}

	@FXML
	private void handleRefresh() {
		this.refresh();
	}

	private void refresh() {
		if (this.store == null) {
			this.messageLabel.setText("Books file not available.");
			this.tableView.setItems(FXCollections.observableArrayList());

			return;
		}

		List<Book> all = this.store.getAllBooks();
		ObservableList<Book> obs = FXCollections.observableArrayList(all);

		this.tableView.setItems(obs);
		this.messageLabel.setText("Loaded " + all.size() + " books.");
	}
}
