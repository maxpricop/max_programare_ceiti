import java.util.Scanner;
import java.lang.Math;

public class Main {
	public static void main(String[] args) {
		Scanner inputScanner = new Scanner(System.in);

		System.out.println("Alege exercitiul care sa fie rulat:");
		System.out.println("1 - Suma & Diferenta a doua numere");
		System.out.println("2 - Produs & Cat a doua numere");
		System.out.println("3 - Media aritmetica & geometrica a doua numere naturale");
		System.out.println("4 - Aria & perimetrul unui patrat");
		System.out.println("5 - Aria & volumul unui cub");
		System.out.println("6 - Aria & lungimea unui cerc");
		System.out.println("7 - Raza & aria unui cerc");
		System.out.println("8 - Perimetrul, unghiul interior, numarul de diagonale & raza cercului inscris");
		System.out.println("9 - Distanta & mijlocul a doua coordonate");
		System.out.print("Introdu numarul exercitiului (1-9): ");

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
			case 6: {
				ex6(inputScanner);
				break;
			}
			case 7: {
				ex7(inputScanner);
				break;
			}
			case 8: {
				ex8(inputScanner);
				break;
			}
			case 9: {
				ex9(inputScanner);
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

		if (secondNumber == 0) {
			System.out.println("Impartirea la zero nu este posibila.");
			return;
		}

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

		if (firstNumber < 0 || secondNumber < 0) {
			System.out.println("Numerele trebuie sa fie naturale (pozitive).");
			return;
		}

		double arithmeticMean = ((double) (firstNumber + secondNumber)) / 2;
		double geometricMean = Math.sqrt(firstNumber * secondNumber);

		System.out.println("Media aritmetica a celor doua numere este: " + arithmeticMean);
		System.out.println("Media geometrica a celor doua numere este: " + geometricMean);
	}

	public static void ex4(Scanner scanner) {
		System.out.print("Introdu lungimea laturii patratului: ");
		double sideLength = scanner.nextDouble();

		double area = Math.pow(sideLength, 2);
		double perimeter = 4 * sideLength;

		System.out.println("Aria patratului este: " + area);
		System.out.println("Perimetrul patratului este: " + perimeter);
	}

	public static void ex5(Scanner scanner) {
		System.out.print("Introdu lungimea laturii cubului: ");
		double sideLength = scanner.nextDouble();

		double area = 6 * Math.pow(sideLength, 2);
		double volume = Math.pow(sideLength, 3);

		System.out.println("Aria cubului este: " + area);
		System.out.println("Volumul cubului este: " + volume);
	}

	public static void ex6(Scanner scanner) {
		System.out.print("Introdu lungimea raza cercului: ");
		double radius = scanner.nextDouble();

		double area = Math.PI * Math.pow(radius, 2);
		double circumference = 2 * Math.PI * radius;

		System.out.println("Aria cercului este: " + area);
		System.out.println("Circumferinta cercului este: " + circumference);
	}

	public static void ex7(Scanner scanner) {
		System.out.print("Introdu lungimea cercului: ");
		double circumference = scanner.nextDouble();

		double radius = circumference / (2 * Math.PI);
		double area = Math.PI * radius * radius;

		System.out.println("Raza cercului este: " + radius);
		System.out.println("Aria cercului este: " + area);
	}

	public static void ex8(Scanner scanner) {
		System.out.print("Introdu numarul de laturi a unui poligon regulat: ");
		int numberOfSides = scanner.nextInt();

		if (numberOfSides < 3) {
			System.out.println("Un poligon trebuie sa aiba cel putin 3 laturi.");
			return;
		}

		System.out.print("Introdu raza cercului circumscris: ");
		double circumscribedRadius = scanner.nextDouble();

		if (circumscribedRadius <= 0) {
			System.out.println("Raza cercului trebuie sa fie un numar pozitiv.");
			return;
		}

		double polygonPerimeter = 2 * numberOfSides * circumscribedRadius * Math.sin(Math.PI / numberOfSides);
		double area = (numberOfSides * Math.pow(circumscribedRadius, 2) / 2) * Math.sin(2 * Math.PI / numberOfSides);
		double angle = (numberOfSides - 2) * 180 / numberOfSides;
		double diagonals = (numberOfSides * (numberOfSides - 3)) / 2;
		double inscribedRadius = circumscribedRadius * Math.cos(Math.PI / numberOfSides);

		System.out.println("Perimetrul poligonului este: " + polygonPerimeter);
		System.out.println("Aria poligonului este: " + area);
		System.out.println("Masura unghiului interior al poligonului este: " + angle);
		System.out.println("Numarul de diagonale ale poligonului este: " + diagonals);
		System.out.println("Raza cercului inscris poligonului este: " + inscribedRadius);
	}

	public static void ex9(Scanner scanner) {
		System.out.print("Introdu coordonata x a punctului A: ");
		double ax = scanner.nextDouble();

		System.out.print("Introdu coordonata y a punctului A: ");
		double ay = scanner.nextDouble();

		System.out.print("Introdu coordonata x a punctului B: ");
		double bx = scanner.nextDouble();

		System.out.print("Introdu coordonata y a punctului B: ");
		double by = scanner.nextDouble();

		double distance = Math.sqrt(Math.pow((bx - ax), 2) + Math.pow((by - ay), 2));
		double midpointX = (ax + bx) / 2;
		double midpointY = (ay + by) / 2;

		System.out.println("Distanta dintre cele doua puncte este: " + distance);
		System.out.println("Coordonatele mijlocului segmentului AB sunt: (" + midpointX + ", " + midpointY + ")");
	}
}