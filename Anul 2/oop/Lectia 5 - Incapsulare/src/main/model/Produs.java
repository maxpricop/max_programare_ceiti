package main.model;

public class Produs {
	private String nume;
	private double pret;

	public void setNume(String newName) {
		if (newName == null) throw new IllegalArgumentException("Nume nu poate fi null");

		String tName = newName.trim();
		if (tName.isEmpty()) throw new IllegalArgumentException("Nume nu poate fi gol");
		if (tName.length() < 2 || tName.length() > 100) throw new IllegalArgumentException("Nume trebuie să aibă între 2 și 100 caractere");
		if (!tName.matches("^[\\p{L}0-9 .,'-]+$")) throw new IllegalArgumentException("Nume conține caractere nepermise");

		this.nume = tName;
	}

	public void setPret(double newPrice) {
		if (Double.isNaN(pret) || Double.isInfinite(pret)) throw new IllegalArgumentException("Pret invalid");
		if (pret < 0.0) throw new IllegalArgumentException("Pret nu poate fi negativ");

		this.pret = newPrice;
	}

	public String getNume() {
		return this.nume;
	}

	public double getPret() {
		return this.pret;
	}
}