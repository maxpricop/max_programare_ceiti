import java.util.Scanner;
import java.util.Set;
import java.util.LinkedHashSet;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        exercise(scanner);

        scanner.close();
    }

    static void exercise(Scanner scanner) {
        System.out.print("Introdu marimea array-ului: ");
        int n = scanner.nextInt();
        int[] array = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.print("Introdu elementul " + (i + 1) + ": ");
            array[i] = scanner.nextInt();
        }

        int sum = 0;

        int evenProduct = 1;
        int eventCount = 0;

        int oddSum = 0;

        for (int element : array) {
            sum += element;

            if (element % 2 == 0) {
                evenProduct *= element;
                eventCount++;
            } else {
                oddSum += element;
            }
        }

        System.out.println("Media aritmetica: " + (float) sum / n);
        System.out.println("Produsul elementelor pare: " + evenProduct);
        System.out.println("Numarul de elemente pare: " + eventCount);
        System.out.println("Suma elementelor impare: " + oddSum);

        System.out.println("Elementele array-ului in ordine: ");
        for (int element : array) {
            System.out.print(element + " ");
        }
        System.out.println();

        System.out.println("Elementele array-ului in ordine inversa: ");
        for (int i = n - 1; i >= 0; i--) {
            System.out.print(array[i] + " ");
        }

        Set<Integer> unique = new LinkedHashSet<Integer>();
        for (int element : array) {
            unique.add(element);
        }

        System.out.println();
        System.out.println("Elementele unice (fara duplicate): ");
        for (int f : unique) {
            System.out.print(f + " ");
        }
        System.out.println();
    }
}
