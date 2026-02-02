import model.Arrays;

public class Main {
    public static void main(String[] args) {
        Arrays Arrays = new Arrays(new int[][] { {}, { 3, 5, 7, 68 }, { 2, 6, 5, 8, 10 } });

        Arrays.displayLengths();
        System.out.println("--------------");
        Arrays.displayArray();
        System.out.println("--------------");
        Arrays.displaySumEvenNumbers();
        System.out.println("--------------");
        Arrays.displaySumOddNumbers();
        System.out.println("--------------");
        Arrays.displayMaxInRows();
    }
}
