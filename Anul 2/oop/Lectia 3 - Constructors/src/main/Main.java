package main;

import main.model.Masina;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Introduceti kilometrajul de plecare: ");
        int plecare = sc.nextInt();

        System.out.print("Introduceti kilometrajul de sosire: ");
        int sosire = sc.nextInt();

        System.out.print("Introduceti cantitatea de litri consumata: ");
        double litri = sc.nextDouble();

        Masina masina = new Masina(plecare, sosire, litri);
        Masina masina2 = new Masina(masina);

        System.out.print("Consumul masinii este: " + masina2.consum());

        sc.close();
    }
}
