#include <iostream>

using namespace std;

/*Exercitiul 14 (a) pagina 23 Turbo Pascal Culegere
Sa se rezolve ecuatia: ax + b = 0*/
int main() {
    // Declararea celor 2 numere din ecuatie
    float a, b;

    // Introducerea numerelor de utilizator
    cout << "Introdu numarul a: ";
    cin >> a;
    cout << "Introdu numarul b: ";
    cin >> b;

    // Calcularea si afisarea solutiei
    (a == 0)
        ? cout << "Solutia ecuatiei " << a << "x" << " + " << b << " de gradul 1: x = orice numar (a este 0)" << endl
        : cout << "Solutia ecuatiei " << a << "x" << " + " << b << " de gradul 1: x = " << -b / a << endl;

    return 0;
}