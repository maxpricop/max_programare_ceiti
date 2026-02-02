package main;

import main.model.Elev;
import main.model.Telefon;

public class Main {
	public static void main(String[] args) {
		Elev elev1 = new Elev("Neculce Loredana", 8);
		Elev elev2 = new Elev("Deleanu Alexandra", 9);
		Elev elev3 = new Elev("Obreja Anton", 7);

		elev1.afiseazaProfil();
		System.out.println();

		elev2.afiseazaProfil();
		System.out.println();

		elev3.afiseazaProfil();
		System.out.println();

		Elev.afiseazaStatistici();

		System.out.println();
		System.out.println();
		System.out.println();

		Telefon telefon1 = new Telefon("Romana", 70, "Mama, Tata, Ana");
		Telefon telefon2 = new Telefon("Engleza", 50, "John, Alice, Bob");

		telefon1.afiseazaVolumMaxim();
		telefon2.afiseazaVolumMaxim();
		System.out.println();

		telefon1.afiseazaSetariTelefon();
		System.out.println();

		telefon2.afiseazaSetariTelefon();
		System.out.println();
	}
}
