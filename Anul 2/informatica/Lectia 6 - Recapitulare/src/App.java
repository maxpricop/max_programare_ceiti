import java.util.Scanner;
import arrays.SpecialArray;

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        SpecialArray specialArray = new SpecialArray();

        while (true) {
            System.out.println("Meniu:");
            System.out.println("1. Introdu array-ul");
            System.out.println("2. Afla elementul maxim si nr. de repetitii");
            System.out.println("3. Afla elementul minim si pozitiile lui");
            System.out.println("4. Elementul maxim ce nu trece de un numar introdus");
            System.out.println("5. Iesire din program");
            System.out.print("Optiunea aleasa: ");
            int userChoice = sc.nextInt();

            System.out.println();
            System.out.println();

            switch (userChoice) {
                case 1: {
                    System.out.print("Introdu lungimea array-ului: ");
                    int arrayLength = sc.nextInt();

                    int[] newArray = new int[arrayLength];

                    for (int i = 0; i < arrayLength; i++) {
                        System.out.print("Introdu valoarea elementului " + i + ": ");
                        newArray[i] = sc.nextInt();
                    }

                    specialArray.setArray(newArray);
                    break;
                }
                case 2: {
                    int maxElement = specialArray.getMaxElement();
                    int maxCounter = specialArray.countElement(maxElement);

                    System.out.println("Elementul maxim este " + maxElement + " si apare de " + maxCounter + " ori");
                    break;
                }
                case 3: {
                    int minElement = specialArray.getMinElement();
                    int[] minElementIndexes = specialArray.getIndexesOfElement(minElement);

                    System.out.print("Elementul minim este " + minElement + " si se gaseste la urmatorii indexes: ");
                    for (int index : minElementIndexes) {
                        System.out.print(index);
                    }

                    System.out.println();
                    break;
                }
                case 4: {
                    System.out.print("Intodu valoarea maxima de care nu pot trece elementele: ");
                    int limit = sc.nextInt();

                    int max = specialArray.getMaxElementUnderLimit(limit);

                    System.out.println("Elementul maxim ce nu trece de " + limit + " este " + max);
                    break;
                }
                case 5: {
                    System.out.println("Program inchis cu succes");
                    sc.close();
                    return;
                }
                default: {
                    System.out.println("Valoare invalida");
                    break;
                }
            }
        }
    }

}
