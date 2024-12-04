#include <iostream>

using namespace std;

/*Exercitiul 17 pagina 14 Turbo Pascal Culegere
Se da numerele naturale n si d, n > d
Sa se afle restul si catul impartirii lui n la d*/
int main() {
    // Declararea variabilelor
    unsigned n, d;

    // Introducerea numerelor de catre utilizator
    cout << "Introdu nr. n: ";
    cin >> n;
    cout << "Introdu nr. d: ";
    cin >> d;

    // Calcularea si afisarea rezultatelor
    cout << "Restul impartirii lui n la d: " << n % d << endl;
    cout << "Catul impartirii lui n la d: " << n / d << endl;

    return 0;
}