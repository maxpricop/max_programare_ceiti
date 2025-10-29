import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner inputScanner = new Scanner(System.in);

        System.out.println("Alege Optiunea: ");
        System.out.println("1 - Calcularea bursei");
        System.out.println("2 - Lunile cu n numar de zile");
        System.out.println("3 - Calendar Japonez, anii animalelor");
        System.out.println("4 - Iesire");
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
                System.out.println("Program Inchis.");
                break;
            }
            default: {
                System.out.println("Optiunea alesa nu exista.");
                break;
            }
        }

        inputScanner.close();
    }

    public static void exercise1(Scanner scanner) {
        System.out.print("Introduceti media notelor: ");
        float averageGrade = scanner.nextFloat();
        float bursa = 0;

        if (averageGrade > 10 || averageGrade < 1) { System.out.println("Media introdusa nu este valida."); return; }

        if (averageGrade >= 5 && averageGrade < 7) bursa = 100;
        else if (averageGrade >= 7 && averageGrade < 8) bursa = 20 * averageGrade;
        else if (averageGrade >= 8 && averageGrade < 10) bursa = 25 * averageGrade;
        else bursa = 300;

        System.out.println("Bursa calculata este: " + bursa + " lei.");
    }

    public static void exercise2(Scanner scanner) {
        System.out.print("Introduceti numarul de zile: ");
        short days = scanner.nextShort();

        switch (days) {
            case 28: {
                System.out.println("Lunile cu 28 de zile sunt: Februarie in an normal.");
                break;
            }
            case 29: {
                System.out.println("Lunile cu 29 de zile sunt: Februarie in an bisect.");
                break;
            }
            case 30: {
                System.out.println("Lunile cu 30 de zile sunt: Aprilie, Iunie, Septembrie, Noiembrie.");
                break;
            }
            case 31: {
                System.out.println("Lunile cu 31 de zile sunt: Ianuarie, Martie, Mai, Iulie, August, Octombrie, Decembrie.");
                break;
            }
            default: {
                System.out.println("Nu exista luni cu " + days + " zile.");
                break;
            }
        }
    }

    public static void exercise3(Scanner scanner) {
        System.out.print("Introduceti anul: ");
        int year = scanner.nextShort();
        String animal;

        int yearIndex = (year - 4) % 12;

        switch (yearIndex) {
            case 0: {
                animal = "Sobolan";
                break;
            }
            case 1: {
                animal = "Bou";
                break;
            }
            case 2: {
                animal = "Tigru";
                break;
            }
            case 3: {
                animal = "Iepure";
                break;
            }
            case 4: {
                animal = "Dragon";
                break;
            }
            case 5: {
                animal = "Sarpe";
                break;
            }
            case 6: {
                animal = "Cal";
                break;
            }
            case 7: {
                animal = "Oaie";
                break;
            }
            case 8: {
                animal = "Maimuta";
                break;
            }
            case 9: {
                animal = "Cocos";
                break;
            }
            case 10: {
                animal = "Caine";
                break;
            }
            case 11: {
                animal = "Porc";
                break;
            }
            default: {
                animal = "Necunoscut";
                break;
            }
        }

        System.out.println("Anul " + year + " este anul animalului: " + animal + ".");
    }
}
