#include <iostream>

using namespace std;

/*Exercitiul 8 pagina 14 Turbo Pascal Culegere
Calcularea produsului si catului a 2 numere intregi*/
int main() {
    // Declararea celor 2 numere
    int numar1, numar2;

    // Introducerea numerelor de catre utilizator
    cout << "Introdu nr. 1: ";
    cin >> numar1;
    cout << "Introdu nr. 2: ";
    cin >> numar2;

    // Afisarea rezultatelor calculelor
    cout << "Produsul variabilelor: " << numar1 * numar2 << endl;
    cout << "Catul numerelor: " << numar1 / numar2 << endl;

    return 0;
}