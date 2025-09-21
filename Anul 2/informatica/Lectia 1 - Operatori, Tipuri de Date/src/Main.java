import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner inputScanner = new Scanner(System.in);

		System.out.println("Alege exercitiul care sa fie rulat:");
		System.out.println("1 - Suma & Diferenta a doua numere");
		System.out.println("2 - Produs & Cat a doua numere");
		System.out.println("3 - Media aritmetica & geometrica a doua numere naturale");
		System.out.println("4 - Aria & perimetrul unui patrat");
		System.out.println("5 - Aria & volumul unui cub");
		System.out.print("Introdu numarul exercitiului (1-5): ");

		int choice = inputScanner.nextInt();
		switch (choice) {
			case 1: {
				ex1(inputScanner);
				break;
			}
			case 2: {
				ex2(inputScanner);
				break;
			}
			case 3: {
				ex3(inputScanner);
				break;
			}
			case 4: {
				ex4(inputScanner);
				break;
			}
			case 5: {
				ex5(inputScanner);
				break;
			}
			default: {
				System.out.println("Exercitiul ales nu exista.");
				break;
			}
		}

		inputScanner.close();
	}

	public static void ex1(Scanner scanner) {

		System.out.print("Introdu primul numar: ");
		int firstNumber = scanner.nextInt();

		System.out.print("Introdu al doilea numar: ");
		int secondNumber = scanner.nextInt();

		int sum = firstNumber + secondNumber;
		int difference = firstNumber - secondNumber;

		System.out.println("Suma celor doua numere este: " + sum);
		System.out.println("Diferenta celor doua numere este: " + difference);

	}

	public static void ex2(Scanner scanner) {
		System.out.print("Introdu primul numar: ");
		int firstNumber = scanner.nextInt();

		System.out.print("Introdu al doilea numar: ");
		int secondNumber = scanner.nextInt();

		int product = firstNumber * secondNumber;
		float quotient = ((float) firstNumber) / secondNumber;

		System.out.println("Produsul celor doua numere este: " + product);
		System.out.println("Catul celor doua numere este: " + quotient);
	}

	public static void ex3(Scanner scanner) {
		System.out.print("Introdu primul numar: ");
		int firstNumber = scanner.nextInt();

		System.out.print("Introdu al doilea numar: ");
		int secondNumber = scanner.nextInt();

		float arithmeticMean = ((float) (firstNumber + secondNumber)) / 2;
		double geometricMean = Math.sqrt(firstNumber * secondNumber);

		System.out.println("Media aritmetica a celor doua numere este: " + arithmeticMean);
		System.out.println("Media geometrica a celor doua numere este: " + geometricMean);
	}

	public static void ex4(Scanner scanner) {
		System.out.print("Introdu lungimea laturii patratului: ");
		float sideLength = scanner.nextFloat();

		float area = sideLength * sideLength;
		float perimeter = 4 * sideLength;

		System.out.println("Aria patratului este: " + area);
		System.out.println("Perimetrul patratului este: " + perimeter);
	}

	public static void ex5(Scanner scanner) {
		System.out.print("Introdu lungimea laturii cubului: ");
		float sideLength = scanner.nextFloat();

		float area = 6 * sideLength * sideLength;
		float volume = sideLength * sideLength * sideLength;

		System.out.println("Aria cubului este: " + area);
		System.out.println("Volumul cubului este: " + volume);
	}
}