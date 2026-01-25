package main;

import main.model.Masina;
import main.model.Persoana;

public class Main {
	public static void main(String[] args) {
		Persoana p = new Persoana("Ion", 25);
		Masina m = new Masina("BMW", 2020);

		p.afiseazaInfo();
		m.afiseazaInfo();
	}
}