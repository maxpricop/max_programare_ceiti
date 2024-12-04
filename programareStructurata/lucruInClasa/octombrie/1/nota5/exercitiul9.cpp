#include <cmath>
#include <iostream>

using namespace std;

/*Exercitiul 9 pagina 14 Turbo Pascal Culegere
Calcularea mediei artimetice si geometrice a 2 numere naturale*/
int main()
{
    // Declararea celor 2 numere
    unsigned numar1, numar2;

    // Introducerea numerelor de catre utilizator
    cout << "Introdu nr. 1: ";
    cin >> numar1;
    cout << "Introdu nr. 2: ";
    cin >> numar2;

    // Calcularea si afisarea rezultatelor
    cout << "Media Aritmetica: " << (numar1 + numar2) / 2 << endl;
    cout << "Media Geometrica: " << sqrt(numar1 * numar2) << endl;

    return 0;
}