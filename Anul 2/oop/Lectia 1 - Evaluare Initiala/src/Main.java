import java.util.Scanner;
import exercises.Basic;
import exercises.Student;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Alege exeritiile ce vrei sa le vezi:");
        System.out.println("1. Exercitiile simple de baza");
        System.out.println("2. Exercitiile cu stundentii");
        System.out.print("Optiunea aleasa: ");
        int userChoice = sc.nextInt();

        System.out.println();
        System.out.println();

        switch (userChoice) {
            case 1: {
                basicExercises(sc);
                break;
            }
            case 2: {
                studentExercises(sc);
                break;
            }
            default: {
                System.out.println("Optiunea aleasa nu este valida");
                break;
            }
        }

        sc.close();
    }

    private static void basicExercises(Scanner sc) {
        System.out.println("Alege exercitiul:");
        System.out.println("1. Student discount");
        System.out.println("2. Sistem de operare");
        System.out.println("3. Inversare string");
        System.out.println("4. Valoarea maxima din array");
        System.out.print("Optiunea aleasa: ");
        int userChoice = sc.nextInt();

        System.out.println();
        System.out.println();

        switch (userChoice) {
            case 1: {
                String response = Basic.studentDiscount(true);
                System.out.println(response);

                break;
            }
            case 2: {
                System.out.print("Introdu numele unui sistem de operare: ");
                String selectedOs = sc.next();

                String osFact = Basic.osFact(selectedOs);

                System.out.println(osFact);
                break;
            }
            case 3: {
                System.out.print("Introdu un string: ");
                String selectedString = sc.next();

                String invertedString = Basic.invertString(selectedString);

                System.out.println("Stringul inversat este: " + invertedString);
                break;
            }
            case 4: {
                int[] arr = new int[10];

                System.out.println("Introdu un array cu 10 elemente:");
                for (int i = 0; i < 10; i++) {
                    System.out.print("Introdu elementul " + (i + 1) + ": ");
                    arr[i] = sc.nextInt();
                }

                int maxElement = Basic.maxArrayValue(arr);
                System.out.println("Elementul maxim din array este: " + maxElement);
                break;
            }
            default: {
                System.out.println("Optiunea aleasa nu este valida");
                break;
            }
        }
    }

    private static void studentExercises(Scanner sc) {
        int[] grades1 = { 8, 8, 9, 10, 7 };
        Student s1 = new Student("Razvan", grades1);

        int[] grades2 = { 9, 7, 8, 10, 9 };
        Student s2 = new Student("Ana", grades2);

        int[] grades3 = { 6, 7, 8, 6, 7 };
        Student s3 = new Student("Mihai", grades3);

        int[] grades4 = { 10, 9, 9, 10, 10 };
        Student s4 = new Student("Elena", grades4);

        int[] grades5 = { 5, 6, 7, 8, 6 };
        Student s5 = new Student("Cristi", grades5);

        Student[] students = { s1, s2, s3, s4, s5 };

        System.out.println("Alege optiunea:");
        System.out.println("1. Afiseaza lista studentilor");
        System.out.println("2. Afiseaza mediile studentilor");
        System.out.println("3. Afiseaza cel mai bun stuent");
        System.out.print("Optiunea aleasa: ");
        int userChoice = sc.nextInt();

        System.out.println();
        System.out.println();

        switch (userChoice) {
            case 1: {
                System.out.println("Numele studentilor: ");
                for (Student student : students) {
                    System.out.print(student.getName() + " ");
                }

                break;
            }
            case 2: {
                System.out.println("Mediile studentilor: ");
                for (Student student : students) {
                    System.out.println(student.getName() + " - " + student.gradeAvereage());
                }

                break;
            }
            case 3: {
                Student bestStudent = students[0];

                for (Student student : students) {
                    if (student.gradeAvereage() > bestStudent.gradeAvereage()) bestStudent = student;
                }

                System.out.println("Cel mai bun student este " + bestStudent.getName() + " (" + bestStudent.gradeAvereage() + ")");
                break;
            }
            default: {
                System.out.println("Optiunea aleasa nu este valida");
                break;
            }
        }
    }
}
