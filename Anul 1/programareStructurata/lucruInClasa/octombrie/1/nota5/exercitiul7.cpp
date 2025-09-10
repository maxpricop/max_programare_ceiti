#include <iostream>

using namespace std;

/*Exercitiul 7 pagina 14 Turbo Pascal Culegere
Calcularea sumei si diferentei a 2 numere intregi*/
int main() {
    // Declararea a 2 numere;
    int numar1, numar2;

    // Introducerea numerelor de catre utilizator
    cout << "Introdu nr. 1: ";
    cin >> numar1;
    cout << "Introdu nr. 2: ";
    cin >> numar2;

    // Calcularea si afisarea rezultatelor finale
    cout << "Suma Numerelor: " << numar1 + numar2 << endl;
    cout << "Diferenta Numerelor: " << numar1 - numar2 << endl;

    return 0;
}