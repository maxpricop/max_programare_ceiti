import java.util.Scanner;

import services.DateExamples;
import services.DateExercises;

public class App {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean running = true;

        while (running) {
            displayMenu();
            System.out.print("Alegeti o optiune: ");

            String input = scanner.nextLine();
            int choice;

            try {
                choice = Integer.parseInt(input);
            } catch (NumberFormatException e) {
                System.out.println("\nEroare: Introduceti un numar valid!\n");
                continue;
            }

            System.out.println();

            switch (choice) {
                case 0: {
                    running = false;
                    System.out.println("Program terminat!");
                    break;
                }

                // Solved examples
                case 1: {
                    DateExamples.displayDateFormats();
                    break;
                }
                case 2: {
                    DateExamples.validateDate();
                    break;
                }
                case 3: {
                    DateExamples.daysBetweenDates();
                    break;
                }
                case 4: {
                    DateExamples.checkFutureOrPast();
                    break;
                }
                case 5: {
                    DateExamples.parseStringToDate();
                    break;
                }

                // Exercises
                case 6: {
                    DateExercises.calculateAge(scanner);
                    break;
                }
                case 7: {
                    DateExercises.fridayThe13ths();
                    break;
                }
                case 8: {
                    DateExercises.dayOfWeek(scanner);
                    break;
                }
                case 9: {
                    DateExercises.easterDate(scanner);
                    break;
                }
                case 10: {
                    DateExercises.sundaysBetweenDates(scanner);
                    break;
                }

                default: {
                    System.out.println("Optiune invalida! Alegeti o optiune intre 0 si 10.");
                }
            }

            if (running && choice >= 0 && choice <= 10) {
                System.out.println("\nApasati Enter pentru a continua...");

                scanner.nextLine();
            }
        }

        scanner.close();
    }

    private static void displayMenu() {
        System.out.println("\n========================================");
        System.out.println("       Laborator DateFormat");
        System.out.println("========================================");
        System.out.println();
        System.out.println("--- Exemple Rezolvate ---");
        System.out.println("1. Afisare data curenta in diferite formate");
        System.out.println("2. Validare data");
        System.out.println("3. Calculare diferenta in zile intre doua date");
        System.out.println("4. Verificare daca o data este in viitor sau trecut");
        System.out.println("5. Transformare string in LocalDate");
        System.out.println();
        System.out.println("--- Exercitii ---");
        System.out.println("6. Calculare varsta din data nasterii");
        System.out.println("7. Afisare toate zilele de Vineri 13 (2000-2030)");
        System.out.println("8. Introducere data si afisare ziua saptamanii");
        System.out.println("9. Afisare data Pastelui pentru un an dat");
        System.out.println("10. Afisare toate duminicile dintr-un interval");
        System.out.println();
        System.out.println("0. Iesire");
        System.out.println("========================================");
    }
}
