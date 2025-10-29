import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner inputScanner = new Scanner(System.in);

        System.out.println("Alege exercitiul: ");
        System.out.println("Exercitul 1 - operatii de min si max cu 2 numere");
        System.out.println("Exercitul 2 - operatii de min si max cu 3 numere");
        System.out.println("Exercitul 3 - functii matematice");
        System.out.println("Exercitul 4 - numere consecutive");
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
            case 3: {
                exercise3(inputScanner);
                break;
            }
            case 4: {
                exercise4(inputScanner);
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

        double maxOfNumbers = max(number1, number2, number3);
        double minOfNumbers = min(number1, number2, number3);

        double result5 = 4 - 2 * max(number1, number2, number1 + number2 - number3);
        double result6 = Math.pow(max(number1 - number2, number2 - number3, number1 - number3), 2) - 1;

        System.out.println("max(a, b, c): " + maxOfNumbers);
        System.out.println("min(a, b, c): " + minOfNumbers);
        System.out.println("max(a, b, c) / min(a, b, c): " + (maxOfNumbers / minOfNumbers));
        System.out.println("3 * max(a, b, c): " + (3 * maxOfNumbers));
        System.out.println("4 - 2 * max(a, b, a + b - c): " + result5);
        System.out.println("(max(a - b, b - c, a - c))^2 - 1 = " + result6);
    }

    public static void exercise3(Scanner scanner) {
        System.out.print("Introdu numarul x: ");
        double number = scanner.nextDouble();

        // First function
        if (number < -5) System.out.println("f(x) = x^2 = " + Math.pow(number, 2));
        else if (-5 <= number && number < 2) System.out.println("f(x) = x + 1 = " + (number + 1));
        else System.out.println("f(x) = x^3 = " + Math.pow(number, 3));

        // Second function
        if (number < 0) System.out.println("f(x) = cos(x) = " + Math.cos(number));
        else if (number == 0) System.out.println("f(x) = 4");
        else System.out.println("f(x) = sin(x) = " + Math.sin(number));

        // Third function
        if (number < 1) System.out.println("f(x) = 3x + |x - 1| = " + (3 * number + Math.abs(number - 1)));
        else if (1 <= number && number < 6) System.out.println("f(x) = 2");
        else System.out.println("f(x) = log3(x) = " + (Math.log(number) / Math.log(3)));

        // Fourth function
        if (number <= 0) System.out.println("f(x) = 1");
        else if (0 < number && number <= 2) System.out.println("f(x) = x^2 + x = " + (Math.pow(number, 2) + number));
        else System.out.println("f(x) = sin(π * x) = " + Math.sin(Math.PI * number));
    }

    public static void exercise4(Scanner scanner) {
        System.out.print("Introdu primul numar: ");
        int firstNumber = scanner.nextInt();

        System.out.print("Introdu al doilea numar: ");
        int secondNumber = scanner.nextInt();

        if (firstNumber == secondNumber + 1) System.out.println("Numerele sunt consecutive: " + secondNumber + ", " + firstNumber);
        else if (secondNumber == firstNumber + 1) System.out.println("Numerele sunt consecutive: " + firstNumber + ", " + secondNumber);
        else System.out.println("Numerele nu sunt consecutive");
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
