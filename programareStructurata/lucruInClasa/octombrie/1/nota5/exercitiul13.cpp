#include <cmath>
#include <iostream>

using namespace std;

/*Exercitiul 13 pagina 14 Turbo Pascal Culegere
Calcularea razei si ariei unui cerc in baza lungimii*/
int main() {
    // Declararea variabilelor de lungime si raza a cercului;
    float lungimea, raza;

    // Introducerea lungii de catre utilizator
    cout << "Introdu lungimea cercului: ";
    cin >> lungimea;

    // Valoarea absoluta a lungimii, previne numere negative
    lungimea = fabsf(lungimea);

    // Calcularea razei cercului din lungime folosind formula
    raza = lungimea / 2 * M_PI;

    // Calcularea si afisarea rezultatelor
    cout << "Raza Cercului: " << raza << endl;
    cout << "Aria discului: " << M_PI * pow(raza, 2) << endl;

    return 0;
}