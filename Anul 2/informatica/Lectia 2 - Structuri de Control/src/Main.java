import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner inputScanner = new Scanner(System.in);

        System.out.println("Alege exercitiul: ");
        System.out.println("Exercitul 1 - operatii de min si max cu 2 numere");
        System.out.println("Exercitul 2 - operatii de min si max cu 3 numere");
        System.out.print("Optiunea aleasa: ");
        short userChoice = inputScanner.nextShort();

        switch (userChoice) {
            case 1: {
                exercise1(inputScanner);
                break;
            }
            case 2: {
                exercise2(inputScanner);
                break;
            }
            default: {
                System.out.println("Exercitiul ales nu exista.");
                break;
            }
        }

        inputScanner.close();
    }

    public static void exercise1(Scanner scanner) {
        System.out.print("Introdu primul numar: ");
        double number1 = scanner.nextDouble();

        System.out.print("Introdu al doilea numar: ");
        double number2 = scanner.nextDouble();

        System.out.println("max(a, b): " + max(number1, number2));
        System.out.println("min(a, b): " + min(number1, number2));
        System.out.println("max(a, b) + min(a, b): " + (max(number1, number2) + min(number1, number2)));
        System.out.println("max(a - b, b): " + max(number1 - number2, number2));
        System.out.println("min(a + b, b): " + min(number1 + number2, number2));
        System.out.println("max(2a, 3b): " + max(2 * number1, 3 * number2));
    }

    public static void exercise2(Scanner scanner) {
        System.out.print("Introdu primul numar: ");
        double number1 = scanner.nextDouble();

        System.out.print("Introdu al doilea numar: ");
        double number2 = scanner.nextDouble();

        System.out.print("Introdu al treilea numar: ");
        double number3 = scanner.nextDouble();

        System.out.println("max(a, b, c): " + max(number1, number2, number3));
        System.out.println("min(a, b, c): " + min(number1, number2, number3));
        System.out.println("max(a, b, c) / min(a, b, c): " + (max(number1, number2, number3) / min(number1, number2, number3)));
        System.out.println("3 * max(a, b, c): " + (3 * max(number1, number2, number3)));
        System.out.println("4 - 2 * max(a, b, a + b - c): " + (4 - 2 * max(number1, number2, number1 + number2 - number3)));

    }

    public static double max(double... numbers) {
        if (numbers == null || numbers.length == 0) throw new IllegalArgumentException("Functia necesita cel putin 1 argument");

        double maxNumber = numbers[0];
        for (double number : numbers) {
            if (number > maxNumber) maxNumber = number;
        }

        return maxNumber;
    }

    public static double min(double... numbers) {
        if (numbers == null || numbers.length == 0) throw new IllegalArgumentException("Functia necesita cel putin 1 argument");

        double minNumber = numbers[0];
        for (double number : numbers) {
            if (number < minNumber) minNumber = number;
        }

        return minNumber;
    }
}
