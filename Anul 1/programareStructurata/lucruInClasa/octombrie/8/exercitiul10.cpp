#include <iostream>

using namespace std;

/*Exercitiul 10 pagina 22 Turbo Pascal Culegere
Se dau numerele naturale diferite a, b, c.
Sa se afiseze numarul care nu e nici cel mai mare, nici cel mai mic.
Sa se verifice daca ele pot fi termeni consecutivi ai unei progresii aritmetice*/
int main() {
    // Declararea numerelor a, b, c.
    unsigned a, b, c;

    // Introducerea numerelor de utilizator
    cout << "Introdu numarul a: ";
    cin >> a;
    cout << "Introdu numarul b: ";
    cin >> b;
    cout << "Introdu numarul c: ";
    cin >> c;

    // Determinarea celui mai mare numar, numarul mijlociu si cel mai mic numar
    int numarMare = ((a > b && a > c) ? a : (b > a && b > c) ? b : c);
    int numarMijlociu = (((a < b && b < c) || (c < b && b < a)) ? b : ((b < a && a < c) || (c < a && a < b)) ? a : c);
    int numarMic = ((a < b && a < c) ? a : (b < a && b < c) ? b : c);

    // Afisarea numarului mijlociu
    cout << "Numbarul mijlociul este " << numarMijlociu << endl;

    // Calcularea diferentei dintre 2 numere
    int diferentaAritmetica = numarMijlociu - numarMic;

    // Determinarea si afisarea rezultatului
    (numarMijlociu + diferentaAritmetica == numarMare)
        ? cout << "Numerele " << a << ", " << b << ", " << c << " pot forma o progresie aritmetica" << endl
        : cout << "Numerele " << a << ", " << b << ", " << c << " nu pot forma o progresie aritmetica" << endl;

    return 0;
}