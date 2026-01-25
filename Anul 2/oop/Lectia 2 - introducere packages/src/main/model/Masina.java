package main.model;

public class Masina {
	private String marca;
	private int an;

	public Masina(String originalMarca, int originalAn) {
		this.marca = originalMarca;
		this.an = originalAn;
	}

	public void setMarca(String name) {
		this.marca = name;
	}

	public void setAn(int newAn) {
		this.an = newAn;
	}

	public String getMarca() {
		return this.marca;
	}

	public int getAn() {
		return this.an;
	}

	public void afiseazaInfo() {
		System.out.println("Masina: " + marca + ", an: " + an);
	}

}
