package main.model;

public class Persoana {
	private String nume;
	private int varsta;

	public Persoana(String originalNume, int originalVasta) {
		this.nume = originalNume;
		this.varsta = originalVasta;
	}

	public void setNume(String newName) {
		this.nume = newName;
	}

	public void setVarsta(int newVarsta) {
		this.varsta = newVarsta;
	}

	public String getNume() {
		return this.nume;
	}

	public int getVarsta() {
		return this.varsta;
	}

	public void afiseazaInfo() {
		System.out.println("Persoana: " + nume + ", varsta: " + varsta);
	}
}
