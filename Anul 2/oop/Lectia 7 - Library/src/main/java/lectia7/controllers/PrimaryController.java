package lectia7.controllers;

import java.io.IOException;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.layout.StackPane;

import lectia7.storage.FileBookStore;

public class PrimaryController {
	@FXML
	private StackPane contentPane;

	private FileBookStore store;
	private static final String BOOKS_FILE = "data/books.txt";

	@FXML
	public void initialize() {
		try {
			this.store = new FileBookStore(BOOKS_FILE);
		} catch (IOException e) {
			System.err.println("Warning: books file not available: " + e.getMessage());
			this.store = null;
		}

		this.showList();
	}

	public void showAdd() {
		this.loadView("/lectia7/add_book.fxml");
	}

	public void showList() {
		this.loadView("/lectia7/list_books.fxml");
	}

	public void showFind() {
		this.loadView("/lectia7/find_book.fxml");
	}

	private void loadView(String fxmlPath) {
		try {
			FXMLLoader loader = new FXMLLoader(getClass().getResource(fxmlPath));
			Parent view = loader.load();
			Object controller = loader.getController();

			if (controller != null) {
				try {
					controller.getClass().getMethod("setStore", FileBookStore.class).invoke(controller, this.store);
				} catch (NoSuchMethodException ignored) {
				}

				try {
					controller.getClass().getMethod("setPrimaryController", PrimaryController.class).invoke(controller, this);
				} catch (NoSuchMethodException ignored) {
				}
			}

			this.contentPane.getChildren().setAll(view);
		} catch (IOException e) {
			e.printStackTrace();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public FileBookStore getStore() {
		return this.store;
	}
}
