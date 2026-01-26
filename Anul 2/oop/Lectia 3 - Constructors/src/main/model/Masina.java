package main.model;

public class Masina {
	private int kilometrajPlecare;
	private int kilometrajSosire;
	private double litri;

	public Masina() {
		this.kilometrajPlecare = 0;
		this.kilometrajSosire = 0;
		this.litri = 0.0;
	}

	public Masina(int plecare, int sosire, double litri) {
		if (sosire >= plecare) {
			this.kilometrajPlecare = plecare;
			this.kilometrajSosire = sosire;
		} else {
			this.kilometrajPlecare = 0;
			this.kilometrajSosire = 0;
		}

		if (litri >= 0) this.litri = litri;
		else this.litri = 0.0;
	}

	public Masina(Masina altaMasina) {
		this.kilometrajPlecare = altaMasina.kilometrajPlecare;
		this.kilometrajSosire = altaMasina.kilometrajSosire;
		this.litri = altaMasina.litri;
	}

	public double consum() {
		return ((this.kilometrajSosire - this.kilometrajPlecare) / this.litri);
	}
}