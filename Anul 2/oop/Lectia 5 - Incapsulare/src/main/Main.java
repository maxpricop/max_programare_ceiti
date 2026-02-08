package main;

import main.model.Carte;

public class Main {
	public static void main(String[] args) {
		Carte book1 = new Carte("Titlu 1", "Elsa", 1669);
		Carte book2 = new Carte("Titlu 2", "Loki", 1667);

		System.out.println(book1.getTitle() + " - " + book1.getAuthor() + " - " + book1.getPublicationYear());
		System.out.println(book2.getTitle() + " - " + book2.getAuthor() + " - " + book2.getPublicationYear());
	}
}
