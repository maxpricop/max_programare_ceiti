import java.util.Scanner;

public class Main {
	public static void exerciseWithScanner(Scanner scanner) {
		System.out.print("Introduceti un numar real: ");
		float number = scanner.nextFloat();

		int parteIntreaga = (int) number;
		float parteFractionara = number - parteIntreaga;
		long rounded = Math.round(number);

		System.out.println("Partea intreaga: " + parteIntreaga);
		System.out.println("Partea fractionara: " + parteFractionara);
		System.out.println("Rotunjit: " + rounded);
	}

	public static void exerciseWithoutScanner(float number) {
		int parteIntreaga = (int) number;
		float parteFractionara = number - parteIntreaga;
		long rotunjit = Math.round(number);

		System.out.println("Numarul este: " + number);
		System.out.println("Partea intreaga: " + parteIntreaga);
		System.out.println("Partea fractionara: " + parteFractionara);
		System.out.println("Rotunjit: " + rotunjit);
		System.out.println();
	}

	public static void main(String[] args) {
		Scanner inputScanner = new Scanner(System.in);

		System.out.println("Tema 1 - Afiseaza partea intreaga, partea fractionara si rotungirea unui numar real");
		System.out.println("Alegeti versiunea de rezolvare:");
		System.out.println("1. Versiunea fara input (numar fixat in cod)");
		System.out.println("2. Versiunea cu input de la tastatura");
		System.out.print("Alegeti optiunea (1 sau 2): ");
		int selectedOption = inputScanner.nextInt();

		if (selectedOption == 1) exerciseWithoutScanner(12.789f);
		else if (selectedOption == 2) exerciseWithScanner(inputScanner);
		else System.out.println("Optiune invalida");

		inputScanner.close();
	}
}
