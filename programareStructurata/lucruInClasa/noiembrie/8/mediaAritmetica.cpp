#include <iostream>

using namespace std;

// Calcularea mediei aritmetice a n numere, doar pozitive, toate introduse de utilizator.
int main() {
    /*Declarare variabile
    n = numarul de numere ce vor fi introduse
    i = numarul iteratiei
    contor = numarul de numere pozitive introduse pana acum*/
    unsigned n, i = 0, contor = 0;

    // Introducerea numarului de iteratii prin care va trece utilizatorul
    cout << "Cate numere vrei sa introduci: ";
    cin >> n;

    // Declararea sumei totale de numere pozitive
    float suma = 0;

    // Iterare de n ori prin loop
    while (i < n) {
        // Declararea numarului introdus in fiecare rulare de utilizator
        float numar;

        // Introducerea numarului
        cout << "Introdu un numar: ";
        cin >> numar;

        // Incrementarea lui i, cu 1 rulari mai putine de loop
        i++;

        // Daca numarul este pozitiv, este adaugat la suma
        if (numar > 0) {
            suma += numar;
            contor++;
        };
    };

    // Afisarea rezultatului
    if (contor) cout << "Media aritmetica este: " << suma / contor << endl;
    else cout << "Media aritmetica nu poate fi calculata." << endl;

    return 0;
}