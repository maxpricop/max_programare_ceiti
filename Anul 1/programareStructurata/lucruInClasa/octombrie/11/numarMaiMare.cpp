#include <iostream>

using namespace std;

// Determinarea numarului mai mare dintre 2 numere
int main() {
    // Declararea a 2 variabile numerice
    int numar1, numar2;

    // Introducerea numerelor de utilizator
    cout << "Introdu nr. 1: ";
    cin >> numar1;
    cout << "Introdu nr. 2: ";
    cin >> numar2;

    // Determinarea si afisarea numarului mai mare
    if (numar1 > numar2) {
        cout << "Numarul 1 este mai mare ca numarul 2" << endl;
    } else {
        cout << "Numarul 2 este mai mare ca numarul 1" << endl;
    }

    return 0;
}