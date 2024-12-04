#include <iostream>

using namespace std;

/*Exercitiul 13 pagina 23 Turbo Pascal Culegere
Se dau numerele naturale diferite a si b.
Sa se verifice daca b divide a*/
int main() {
    // Declararea numerelor
    unsigned a, b;

    // Introducerea numerelor de utilizator
    cout << "Introdu numarul a: ";
    cin >> a;
    cout << "Introdu numarul b: ";
    cin >> b;

    // Calcularea si afisarea rezultatului
    (b % a == 0) ? cout << "B divide A" << endl : cout << "B nu divided A" << endl;

    return 0;
}