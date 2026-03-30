package services;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.time.temporal.TemporalAdjusters;
import java.util.Scanner;

/**
 * Contains exercises for practicing date manipulation in Java.
 * Most methods require user input via Scanner.
 */
public class DateExercises {
    private static final DateTimeFormatter DATE_FORMATTER = DateTimeFormatter.ofPattern("dd/MM/yyyy");

    /**
     * Calculates the user's age from their birth date.
     */
    public static void calculateAge(Scanner scanner) {
        System.out.print("Introduceti data nasterii (dd/MM/yyyy): ");
        String input = scanner.nextLine();

        try {
            LocalDate birthDate = LocalDate.parse(input, DATE_FORMATTER);
            LocalDate today = LocalDate.now();

            if (birthDate.isAfter(today)) {
                System.out.println("Eroare: Data nasterii nu poate fi in viitor!");

                return;
            }

            Period age = Period.between(birthDate, today);

            System.out.println(
                    "Varsta dumneavoastra: " + age.getYears() + " ani, " + age.getMonths() + " luni si " + age.getDays() + " zile");
        } catch (DateTimeParseException e) {
            System.out.println("Eroare: Format invalid! Folositi formatul dd/MM/yyyy");
        }
    }

    /**
     * Displays all Friday the 13ths between 2000 and 2030.
     */
    public static void fridayThe13ths() {
        System.out.println("Toate zilele de Vineri 13 intre 2000 si 2030:");
        System.out.println("----------------------------------------------");

        int count = 0;
        for (int year = 2000; year <= 2030; year++) {
            for (int month = 1; month <= 12; month++) {
                LocalDate date = LocalDate.of(year, month, 13);
                if (date.getDayOfWeek() != DayOfWeek.FRIDAY) continue;

                System.out.println(date.format(DATE_FORMATTER) + " - Vineri");
                count++;
            }
        }

        System.out.println("----------------------------------------------");
        System.out.println("Total: " + count + " zile de Vineri 13");
    }

    /**
     * Gets a date from the user and displays the day of the week in Romanian.
     */
    public static void dayOfWeek(Scanner scanner) {
        System.out.print("Introduceti o data (dd/MM/yyyy): ");
        String input = scanner.nextLine();

        try {
            LocalDate date = LocalDate.parse(input, DATE_FORMATTER);
            DayOfWeek day = date.getDayOfWeek();
            String romanianDay = getRomanianDay(day);

            System.out.println("Data " + date.format(DATE_FORMATTER) + " este: " + romanianDay);
        } catch (DateTimeParseException e) {
            System.out.println("Eroare: Format invalid! Folositi formatul dd/MM/yyyy");
        }
    }

    /**
     * Calculates and displays the Easter date for a given year.
     * Uses the Anonymous Gregorian algorithm (Meeus/Jones/Butcher).
     */
    public static void easterDate(Scanner scanner) {
        System.out.print("Introduceti anul pentru calculul Pastelui: ");
        String input = scanner.nextLine();

        try {
            int year = Integer.parseInt(input);

            if (year < 1583) {
                System.out.println("Eroare: Acest algoritm functioneaza doar pentru anii >= 1583");

                return;
            }

            LocalDate easter = calculateEaster(year);
            String romanianDay = getRomanianDay(easter.getDayOfWeek());

            System.out.println("Pastele in anul " + year + " este pe: " + easter.format(DATE_FORMATTER) + " (" + romanianDay + ")");
        } catch (NumberFormatException e) {
            System.out.println("Eroare: Introduceti un an valid!");
        }
    }

    /**
     * Displays all Sundays between two user-provided dates.
     */
    public static void sundaysBetweenDates(Scanner scanner) {
        System.out.print("Introduceti data de inceput (dd/MM/yyyy): ");
        String startInput = scanner.nextLine();

        System.out.print("Introduceti data de sfarsit (dd/MM/yyyy): ");
        String endInput = scanner.nextLine();

        try {
            LocalDate startDate = LocalDate.parse(startInput, DATE_FORMATTER);
            LocalDate endDate = LocalDate.parse(endInput, DATE_FORMATTER);

            if (startDate.isAfter(endDate)) {
                System.out.println("Eroare: Data de inceput trebuie sa fie inainte de data de sfarsit!");
                return;
            }

            System.out.println();
            System.out.println("Toate duminicile intre " + startDate.format(DATE_FORMATTER) + " & " + endDate.format(DATE_FORMATTER) + ":");
            System.out.println("----------------------------------------------");

            // Find the first Sunday on or after start date
            LocalDate firstSunday = startDate.with(TemporalAdjusters.nextOrSame(DayOfWeek.SUNDAY));

            int count = 0;
            LocalDate current = firstSunday;
            while (!current.isAfter(endDate)) {
                System.out.println(current.format(DATE_FORMATTER));
                current = current.plusWeeks(1);
                count++;
            }

            System.out.println("----------------------------------------------");
            System.out.println("Total: " + count + " duminici");
        } catch (DateTimeParseException e) {
            System.out.println("Eroare: Format invalid! Folositi formatul dd/MM/yyyy");
        }
    }

    /**
     * Calculates Easter date using the Anonymous Gregorian algorithm.
     */
    private static LocalDate calculateEaster(int year) {
        int a = year % 19;
        int b = year / 100;
        int c = year % 100;
        int d = b / 4;
        int e = b % 4;
        int f = (b + 8) / 25;
        int g = (b - f + 1) / 3;
        int h = (19 * a + b - d - g + 15) % 30;
        int i = c / 4;
        int k = c % 4;
        int l = (32 + 2 * e + 2 * i - h - k) % 7;
        int m = (a + 11 * h + 22 * l) / 451;
        int month = (h + l - 7 * m + 114) / 31;
        int day = ((h + l - 7 * m + 114) % 31) + 1;

        return LocalDate.of(year, month, day);
    }

    /**
     * Returns the Romanian name for a given day of the week.
     */
    private static String getRomanianDay(DayOfWeek day) {
        return switch (day) {
            case MONDAY -> "Luni";
            case TUESDAY -> "Marti";
            case WEDNESDAY -> "Miercuri";
            case THURSDAY -> "Joi";
            case FRIDAY -> "Vineri";
            case SATURDAY -> "Sambata";
            case SUNDAY -> "Duminica";
        };
    }
}
