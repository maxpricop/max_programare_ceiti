package lectia7.storage;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import lectia7.model.Book;

public class FileBookStore {
	private final File file;
	private final ArrayList<Book> books = new ArrayList<>();

	public FileBookStore(String filePath) throws IOException {
		this.file = new File(filePath);

		if (!this.file.exists()) throw new FileNotFoundException("File not found: " + filePath);
		loadFromFile();
	}

	private void loadFromFile() throws IOException {
		this.books.clear();

		try (BufferedReader reader = new BufferedReader(new FileReader(this.file))) {
			String line;

			while ((line = reader.readLine()) != null) {
				if (line.isBlank()) continue;

				this.books.add(Book.fromFileString(line));
			}
		}
	}

	public List<Book> getAllBooks() {
		return new ArrayList<>(this.books);
	}

	public void addBook(Book newBook) {
		this.books.add(newBook);
	}

	public boolean deleteBookByTitle(String title) {
		boolean deleted = this.books.removeIf(book -> book.getTitle().equalsIgnoreCase(title));

		return deleted;
	}

	public Book findBookByTitle(String title) {
		for (Book book : this.books) {
			if (!book.getTitle().equalsIgnoreCase(title)) continue;

			return book;
		}

		return null;
	}

	public void save() throws IOException {
		try (BufferedWriter writer = new BufferedWriter(new FileWriter(this.file))) {
			for (Book book : this.books) {
				writer.write(book.toFileString());
				writer.newLine();
			}
		}
	}
}
