package main.model;

import java.time.Year;

public class Carte {
	private String title;
	private String author;
	private int publicationYear;

	private final int MIN_YEAR = 1500;
	private final int MAX_YEAR = Year.now().getValue();

	public Carte(String originalTitle, String originalAuthor, int originalYear) {
		this.setTitle(originalTitle);
		this.setAuthor(originalAuthor);
		this.setPublicationYear(originalYear);
	}

	public void setTitle(String newTitle) {
		if (newTitle == null) throw new IllegalArgumentException("Titlul nu poate fi null");

		String t = newTitle.trim();
		if (t.isEmpty()) throw new IllegalArgumentException("Titlul nu poate fi gol");
		if (t.length() < 2 || t.length() > 100) throw new IllegalArgumentException("Titlul trebuie să aibă între 2 și 100 caractere");

		this.title = t;
	}

	public void setAuthor(String newAuthor) {
		if (newAuthor == null) throw new IllegalArgumentException("Autorul nu poate fi null");

		String a = newAuthor.trim();
		if (a.isEmpty()) throw new IllegalArgumentException("Autorul nu poate fi gol");
		if (a.length() < 2 || a.length() > 100) throw new IllegalArgumentException("Autorul trebuie să aibă între 2 și 100 caractere");

		this.author = a;
	}

	public void setPublicationYear(int newYear) {
		if (newYear < this.MIN_YEAR) throw new IllegalArgumentException("Anul de publicatie trebuie sa fie dupa " + this.MIN_YEAR);
		if (newYear > this.MAX_YEAR) throw new IllegalArgumentException("Anul de publicatie trebuie sa fie inainte de " + this.MAX_YEAR);

		this.publicationYear = newYear;
	}

	public String getTitle() {
		return this.title;
	}

	public String getAuthor() {
		return this.author;
	}

	public int getPublicationYear() {
		return this.publicationYear;
	}
}
