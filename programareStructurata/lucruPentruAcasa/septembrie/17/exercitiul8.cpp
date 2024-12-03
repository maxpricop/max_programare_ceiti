#include <iostream>

using namespace std;

// Calcularea produsului si catului a 2 numere
int main()
{
    // Declararea celor 2 numere
    int x, y;

    // Introducerea numerelor de catre utilizator
    cout << "Introdu nr. 1: ";
    cin >> x;
    cout << "Introdu nr. 2: ";
    cin >> y;

    // Afisarea rezultatelor calculelor
    cout << "Produsul variabilelor: " << x * y << endl;
    cout << "Catul numerelor: " << x / y << endl;

    return 0;
}