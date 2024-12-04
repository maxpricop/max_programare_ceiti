#include <cmath>
#include <iostream>

using namespace std;

// Eu sunt nr. 26 in catalog, fac exercitiul 9.
int main() {
    /* Declararea variabilele:
    x = nr. introdus de utilizator
    y = rezultatul calcularii*/
    float x, y;

    // Introducerea numarului de catre utilizator
    cout << "Introdu numarul: ";
    cin >> x;

    // Folosirea if-urilor pentru a determina rezultatul functiei
    if (x < -4) y = x + 2 * pow(x, 2) + 6;
    else if (-4 <= x && x <= 4) y = (2 * x * (pow(x, 2) + 1)) / (x + 1);
    else y = 2 * pow(x, 3) + (x - 11) - 7 * pow(x, 2);

    // Afisarea rezultatului
    cout << "Rezultatul este: " << y << endl;

    return 0;
}