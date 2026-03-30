package services;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.Date;

/**
 * Contains solved examples demonstrating date formatting and manipulation in Java.
 * These examples do not require user input.
 */
public class DateExamples {

    /**
     * Displays the current date in multiple formats using SimpleDateFormat.
     */
    public static void displayDateFormats() {
        Date currentDate = new Date();

        SimpleDateFormat format1 = new SimpleDateFormat("dd/MM/yyyy");
        SimpleDateFormat format2 = new SimpleDateFormat("MM-dd-yyyy");
        SimpleDateFormat format3 = new SimpleDateFormat("yyyy.MM.dd");
        SimpleDateFormat format4 = new SimpleDateFormat("EEEE, dd MMMM yyyy");
        SimpleDateFormat format5 = new SimpleDateFormat("dd MMM yyyy HH:mm:ss");

        System.out.println("Data curenta in diferite formate:");
        System.out.println("Format 1 (dd/MM/yyyy): " + format1.format(currentDate));
        System.out.println("Format 2 (MM-dd-yyyy): " + format2.format(currentDate));
        System.out.println("Format 3 (yyyy.MM.dd): " + format3.format(currentDate));
        System.out.println("Format 4 (zi, data completa): " + format4.format(currentDate));
        System.out.println("Format 5 (cu ora): " + format5.format(currentDate));
    }

    /**
     * Validates if a date string is valid using SimpleDateFormat.
     */
    public static void validateDate() {
        String dateToValidate = "31/02/2024";
        String dateFormat = "dd/MM/yyyy";

        SimpleDateFormat sdf = new SimpleDateFormat(dateFormat);
        sdf.setLenient(false);

        System.out.println("Validare data: " + dateToValidate);

        try {
            sdf.parse(dateToValidate);
            System.out.println("Data este valida.");
        } catch (ParseException e) {
            System.out.println("Data NU este valida! (31 februarie nu exista)");
        }

        // Also test a valid date
        String validDate = "28/02/2024";
        System.out.println("\nValidare data: " + validDate);
        try {
            sdf.parse(validDate);
            System.out.println("Data este valida.");
        } catch (ParseException e) {
            System.out.println("Data NU este valida!");
        }
    }

    /**
     * Calculates the difference in days between two dates using LocalDate.
     */
    public static void daysBetweenDates() {
        LocalDate startDate = LocalDate.of(2024, 12, 31);
        LocalDate endDate = LocalDate.now();

        long daysBetween = ChronoUnit.DAYS.between(startDate, endDate);

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd MMMM yyyy");

        System.out.println("Data de inceput: " + startDate.format(formatter));
        System.out.println("Data de sfarsit: " + endDate.format(formatter));
        System.out.println("Diferenta in zile: " + daysBetween + " zile");
    }

    /**
     * Checks if a date is in the future or in the past.
     */
    public static void checkFutureOrPast() {
        LocalDate today = LocalDate.now();
        LocalDate futureDate = LocalDate.of(2030, 6, 15);
        LocalDate pastDate = LocalDate.of(2020, 3, 10);

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd MMMM yyyy");

        System.out.println("Data de azi: " + today.format(formatter));
        System.out.println();

        System.out.println("Verificare: " + futureDate.format(formatter));
        if (futureDate.isAfter(today)) {
            System.out.println("Aceasta data este in VIITOR");
        } else if (futureDate.isBefore(today)) {
            System.out.println("Aceasta data este in TRECUT");
        } else {
            System.out.println("Aceasta data este ASTAZI");
        }

        System.out.println();

        System.out.println("Verificare: " + pastDate.format(formatter));
        if (pastDate.isAfter(today)) {
            System.out.println("Aceasta data este in VIITOR");
        } else if (pastDate.isBefore(today)) {
            System.out.println("Aceasta data este in TRECUT");
        } else {
            System.out.println("Aceasta data este ASTAZI");
        }
    }

    /**
     * Converts a string to a LocalDate object using DateTimeFormatter.
     */
    public static void parseStringToDate() {
        String dateString = "15-08-2024";
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");

        System.out.println("String de convertit: \"" + dateString + "\"");

        LocalDate parsedDate = LocalDate.parse(dateString, formatter);

        System.out.println("LocalDate obtinut: " + parsedDate);
        System.out.println("An: " + parsedDate.getYear());
        System.out.println("Luna: " + parsedDate.getMonthValue() + " (" + parsedDate.getMonth() + ")");
        System.out.println("Zi: " + parsedDate.getDayOfMonth());
        System.out.println("Ziua saptamanii: " + parsedDate.getDayOfWeek());
    }
}
