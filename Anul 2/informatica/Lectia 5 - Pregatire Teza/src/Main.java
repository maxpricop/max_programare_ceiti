import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        short userChoice = 0;

        System.out.println("Alege un exemplu de cod pentru a rula:");
        System.out.println("1. Exemplul cu switch");
        System.out.println("2. Exemplul cu for");
        System.out.println("3. Exemplul cu for si array");
        System.out.println("4. Exemplul cu matrice 1");
        System.out.println("5. Exemplul cu matrice 2");
        System.out.println("6. Exemplul cu gasirea maximului intr-un array");
        System.out.println("0. Iesire");
        userChoice = sc.nextShort();

        switch (userChoice) {
            case 1: {
                example1();
                break;
            }
            case 2: {
                example2();
                break;
            }
            case 3: {
                example3();
                break;
            }
            case 4: {
                example4();
                break;
            }
            case 5: {
                example5();
                break;
            }
            case 6: {
                example6();
                break;
            }
            case 0: {
                System.out.println("Iesire din program.");
                sc.close();
                return;
            }
            default: {
                System.out.println("Alegere invalida. Te rog sa incerci din nou.");
                sc.close();
                return;
            }
        }

        sc.close();
    }

    public static void example1() {
        int x = 3;
        int y = 4;
        int c = 2;

        switch (2 * x % y) {
            case 2: {
                c -= x;
                break;
            }
            case 4: {
                c += y;
                break;
            }
            case 6: {
                c++;
                break;
            }
            default: {
                c = 0;
                break;
            }
        }

        System.out.print(c);

        // Output is -1
        // Explanation: 2 * 3 % 4 = 6 % 4 = 2
        // So, c -= x; is executed, resulting in c = 2 - 3 = -1
        // The other cases are not executed.
    }

    public static void example2() {
        int[] array = { 10, 15, 20, 25, 30, 35 };

        for (int i = 0; i < array.length; i++) {
            array[i] -= 3;
        }

        System.out.print("Tabloul dupa scaderea a 3 din fiecare element: ");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }

        // Output: Tabloul dupa scaderea a 3 din fiecare element: 7 12 17 22 27 32
        // Explanation: Each element in the array is decremented by 3.
    }

    public static void example3() {
        int[] x = { 1, 2, 7, 0, 4, 11, 8, 5 };
        for (int k = 2; k < 6; k++) {
            x[k] -= 2;
            System.out.print(x[k] + " ");
        }

        // Output will be 5 -2 2 9
        // Explanation: The loop iterates from index 2 to 5, decrementing each element by 2.
        // x[2] becomes 5, x[3] becomes -2, x[4] becomes 2, and x[5] becomes 9.
        // The output is printed in a single line.
    }

    public static void example4() {
        int sum = 0;
        int[][] a = { { 0, 1, 2 }, { 5, 4, 3 }, { 8, 6, 7 } };

        for (int i = 1; i < 3; ++i) {
            for (int j = 1; j < 3; ++j) {
                sum += a[i][j];
            }
        }

        System.out.print(sum + " ");

        // Output will be 20
        // Explanation: The nested loop iterates over the elements a[1][1], a[1][2], a[2][1], and a[2][2].
        // The values are 4, 3, 6, and 7 respectively.
        // Their sum is 4 + 3 + 6 + 7 = 20.
    }

    public static void example5() {
        int sum = 0;
        int[][] a = { { 1, 0, -2, 3 }, { -5, 4, 3, 6 } };

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 4; ++j) {
                sum += a[i][j];
            }
        }

        System.out.print(sum);

        // Output will be 10
        // Explanation: The nested loop iterates over all elements of the 2D array.
        // The sum of all elements is 1 + 0 - 2 + 3 - 5 + 4 + 3 + 6 = 10.
    }

    public static void example6() {
        int[] p = { 1, 2, 7, 0, 3, 5 };
        int m = p[0];

        for (int i = 0; i < p.length; i++) {
            if (m < p[i]) m = p[i];
        }

        System.out.println(m);

        // Output will be 7
        // Explanation: The loop iterates through the array to find the maximum value.
        // The maximum value in the array is 7.
    }
}
