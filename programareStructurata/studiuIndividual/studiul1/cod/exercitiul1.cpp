#include <cmath>
#include <iostream>

using namespace std;

// Eu sunt nr. 26 in catalog, fac exercitiul 26.
int main() {
    // Declarare variabile de lungime si latime dreptunghi
    float lungime, latime;

    // Introducerea lungimii si latimii de utilizator
    cout << "Introdu lungimea dreptunghiului: ";
    cin >> lungime;
    cout << "Introdu latimea dreptunghiului: ";
    cin >> latime;

    // Converteste numerele negative in pozitive pentru a preveni rezultate imposibile
    lungime = abs(lungime);
    latime = abs(latime);

    // Calcularea ariei si perimetrului dreptunghiului dupa formule
    float perimetru = 2 * (lungime + latime);
    float aria = lungime * latime;

    // Afisarea rezultatelor
    cout << "Perimetrul dreptunghiului este: " << perimetru << endl;
    cout << "Aria dreptunghiului este: " << aria << endl;

    return 0;
}