package main.model;

public class Telefon {
	private static int standardVolumMaxim = 100;

	private String limbaTelefon;
	private int luminozitate;
	private String contacte;

	public Telefon(String originalLimbaTelefon, int originalLuminozitate, String originalContacte) {
		this.limbaTelefon = originalLimbaTelefon;
		this.luminozitate = originalLuminozitate;
		this.contacte = originalContacte;
	}

	public void afiseazaVolumMaxim() {
		System.out.println("Volumul maxim al telefonului este: " + standardVolumMaxim);
	}

	public void afiseazaSetariTelefon() {
		System.out.println("Limba telefon: " + this.limbaTelefon);
		System.out.println("Luminozitate: " + this.luminozitate);
		System.out.println("Contacte: " + this.contacte);
	}
}
