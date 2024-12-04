#include <cmath>
#include <iostream>

using namespace std;

// Rezolvarea unei ecuatii de gradul 2 (ax^2 + bx + c = 0)
int main() {
    // Declararea numerelor din ecuatie (a, b si c)
    float a, b, c;

    // Introducerea numerelor de utilizator
    cout << "Introdu a: ";
    cin >> a;
    cout << "Introdu b: ";
    cin >> b;
    cout << "Introdu c: ";
    cin >> c;

    // Calcularea delta
    float delta = pow(b, 2) - 4 * a * c;

    // Calcularea si determinarea rezultatelor
    if (a != 0) {
        if (delta <= 0) {
            cout << "Delta e mai mic ca 0, nu e posibila rezolvarea ecuatiei cu numere reale." << endl;
        } else {
            if (delta == 0) {
                cout << "Ecuatia are o solutie, x = " << -b / 2 * a << endl;
            } else {
                cout << "Ecuatia are 2 solutii." << endl;
                cout << "X1 = " << (-b + sqrt(delta)) / 2 * a << endl;
                cout << "X2 = " << (-b - sqrt(delta)) / 2 * a << endl;
            }
        }
    } else {
        cout << "A este 0, nu e posibila rezolvarea ecuatiei" << endl;
    }

    return 0;
}