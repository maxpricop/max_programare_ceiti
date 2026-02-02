package main.model;

public class Elev {
	private static int nrElevi = 0;
	private static double mediaClasei = 0.0;

	private String nume;
	private int nota;

	public Elev(String newName, int newNota) {
		this.nume = newName;
		this.nota = newNota;

		nrElevi++;
		mediaClasei = ((mediaClasei * (nrElevi - 1)) + newNota) / nrElevi;
	}

	public static void afiseazaStatistici() {
		System.out.println("Numar elevi: " + nrElevi);
		System.out.println("Media clasei: " + mediaClasei);
	}

	public void afiseazaProfil() {
		System.out.println("Nume: " + this.nume);
		System.out.println("Nota: " + this.nota);
	}
}
