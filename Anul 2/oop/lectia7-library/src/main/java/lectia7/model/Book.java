package lectia7.model;

import lectia7.util.ValidationUtil;

public class Book {
	private String title;
	private String author;

	public Book(String originalTitle, String originalAuthor) {
		this.setTitle(originalTitle);
		this.setAuthor(originalAuthor);
	}

	public String getTitle() {
		return this.title;
	}

	public String getAuthor() {
		return this.author;
	}

	public void setTitle(String newTitle) {
		ValidationUtil.validateTitle(newTitle);
		this.title = newTitle.trim();
	}

	public void setAuthor(String newAuthor) {
		ValidationUtil.validateAuthor(newAuthor);
		this.author = newAuthor.trim();
	}

	public String toString() {
		return this.title + " de " + this.author;
	}

	public String toFileString() {
		return this.title + '|' + this.author;
	}

	public static Book fromFileString(String line) {
		String[] parts = line.split("\\|");
		if (parts.length != 2) throw new IllegalArgumentException("Invalid book format in file");

		String bookTitle = parts[0];
		String bookAuthor = parts[1];

		return new Book(bookTitle, bookAuthor);
	}
}
