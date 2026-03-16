import model.FileReaderExercises;
import model.BufferedReaderExercises;
import model.FileWriterExercises;
import model.BufferedWriterExercises;

import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("1. FileReader");
            System.out.println("2. BufferedReader");
            System.out.println("3. FileWriter");
            System.out.println("4. BufferedWriter");
            System.out.println("0. Exit");
            System.out.print("Alege o categorie de exercitii: ");

            int classChoice = scanner.nextInt();
            scanner.nextLine();

            if (classChoice == 0) {
                System.out.println("Program inchis cu succes!");

                break;
            }

            switch (classChoice) {
                case 1 -> handleFileReader(scanner);
                case 2 -> handleBufferedReader(scanner);
                case 3 -> handleFileWriter(scanner);
                case 4 -> handleBufferedWriter(scanner);
                default -> System.out.println("Alegere invalida. Incearca din nou.");
            }
        }

        scanner.close();
    }

    private static void handleFileReader(Scanner scanner) {
        System.out.println("\n--- FileReader ---");
        System.out.println("1. Citeste date.txt caracter cu caracter");
        System.out.println("2. Numara caracterele din mesaj.txt");
        System.out.print("Alege un exercitiu: ");

        int choice = scanner.nextInt();
        scanner.nextLine();

        FileReaderExercises exercises = new FileReaderExercises();
        switch (choice) {
            case 1 -> exercises.readCharByChar();
            case 2 -> exercises.countCharacters();
            default -> System.out.println("Alegere invalida.");
        }
    }

    private static void handleBufferedReader(Scanner scanner) {
        System.out.println("\n--- BufferedReader ---");
        System.out.println("1. Citeste text.txt linie cu linie");
        System.out.println("2. Suma numerelor din numere.txt");
        System.out.print("Alege un exercitiu: ");

        int choice = scanner.nextInt();
        scanner.nextLine();

        BufferedReaderExercises exercises = new BufferedReaderExercises();
        switch (choice) {
            case 1 -> exercises.readLineByLine();
            case 2 -> exercises.sumNumbers();
            default -> System.out.println("Alegere invalida.");
        }
    }

    private static void handleFileWriter(Scanner scanner) {
        System.out.println("\n--- FileWriter ---");
        System.out.println("1. Scrie un mesaj in salut.txt");
        System.out.println("2. Scrie numele unui utilizator in utilizator.txt");
        System.out.print("Alege un exercitiu: ");

        int choice = scanner.nextInt();
        scanner.nextLine();

        FileWriterExercises exercises = new FileWriterExercises();
        switch (choice) {
            case 1 -> exercises.writeGreeting();
            case 2 -> exercises.writeUsername(scanner);
            default -> System.out.println("Alegere invalida.");
        }
    }

    private static void handleBufferedWriter(Scanner scanner) {
        System.out.println("\n--- BufferedWriter ---");
        System.out.println("1. Scrie lista de elevi in lista.txt");
        System.out.println("2. Scrie numerele 1-10 in numere.txt");
        System.out.print("Alege un exercitiu: ");

        int choice = scanner.nextInt();
        scanner.nextLine();

        BufferedWriterExercises exercises = new BufferedWriterExercises();
        switch (choice) {
            case 1 -> exercises.writeStudentList();
            case 2 -> exercises.writeNumbers();
            default -> System.out.println("Alegere invalida.");
        }
    }
}
