#include <iostream>
using namespace std;

/* Conditie
Marinei îi plac valorile impare.
Odată ea a scris pe tablă toate numerele naturale de la A la B (inclusiv),
apoi a șters numerele, suma cifrelor căroraeste pară. Determinați câte numere au rămas pe tablă.

Date de intrare. De la tastatură se citesc două numere naturale A și B, separate prin spațiu.
Date de ieşire. La ecran se va afișa numărul natural Sp–
cantitatea de numere cu sumă impară de cifre, dintre cele scrise pe tablă.
Restricţii: 1 ≤ A, B ≤ 10^9*/
int main() {
    unsigned A, B, Sp = 0; // Declararea variabilelor din conditie
    cin >> A >> B;         // Introducerea numerelor din conditie

    // Previne introducerea numerelor care sunt inafara restrictiiei din conditie
    // Nu previn de introducerea a textului deoarace in conditie se zice ca sa introduc 2 numere naturale
    while (A < 1 || A > 1000000000 || B < 1 || B > 1000000000) {
        cout << "Numerele trebuie sa fie intre 1 si 10^9. Reintrodu numerele din nou: ";

        cin.clear();   // Previne erori cauzate de numere introduse ce sunt mai mari ca limita tipului unsigned in bytes
        cin >> A >> B; // Reintroducerea numarului
    }

    // Itereaza prin toate numerele de la A la B
    for (unsigned i = A; i <= B; i++) {

        // Creaza o copie a numarului si o variabila ce tine suma cifrelor a numarului
        unsigned copie = i, sumaCifre = 0;

        // Determina suma cifrelor numarului
        while (copie > 0) {
            unsigned cifra = copie % 10;
            sumaCifre += cifra;

            copie /= 10;
        }

        // Incrementeaza contorul de sume de numere impare daca suma noului numar este impara
        if (sumaCifre % 2 == 1) Sp++;
    }

    // Afisarea rezultatului
    cout << Sp << endl;
    return 0;
}