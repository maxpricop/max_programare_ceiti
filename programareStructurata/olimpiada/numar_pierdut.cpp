#include <iostream>
using namespace std;

/* Conditie
Artur a ales un număr natural n, divizibil prin 6, și a scris pe trei cartele diferite însăși numărul n, jumătatea lui
și o treime a lui. Însă aceste cartele au fost amestecate între ele, apoi una dintre ele s-a pierdut.
Acum Artur are doar două cartele, pe care sunt scrise numerele a & b.
Ajutați-l pe Artur să-și amintească, ce număr Np a fost scris pe cartela pierdută.

Date de intrare. Unica linie a intrării standard conține numerele naturale a și b, separate prin spațiu.

Date de ieşire. Ieșirea standard va conține pe o singură linie naturalul Np-numărul pierdut.

Restricţii: 1 ≤ a, b ≤ 10^9. Se garantează, că datele de intrare sunt astfel, încât există soluție unică.
Timpul de execuţie/test nu va depăşi 0.5 s.
*/

int main() {
    // Declararea variabilelor din conditie
    unsigned a, b, Np;
    cin >> a >> b;

    // Previne introducerea numerelor care sunt inafara restrictiiei din conditie
    // Nu previn de introducerea a textului deoarace in conditie se garanteaza ca datele vor avea o solutie (numerice)
    while (a < 1 || b < 1 || a > 1000000000 || b > 1000000000) {
        cout << "Numerele trebuie sa fie intre 1 si 10^9. Reintrodu numerele din nou: ";

        cin.clear(); // Previne erori cauzate de numere introduse ce sunt mai mari ca limita tipului unsigned in bytes
        cin >> a >> b;
    }

    // Asigura ca a este cel mai mare numar. Foloseste Np ca si o variabila temporara
    if (a < b) {
        Np = a; // Temporar tine a in Np
        a = b;  // Schimba a sa fie b, adica numarul mai mare
        b = Np; // Schimba b sa fie a, adica numar mai mic folosind Np
    }

    // Seteaza Np ca fiind numarul aflat dupa calcule
    if (a % 6 == 0) {
        if (a / 2 == b) Np = a / 3;
        else if (a / 3 == b) Np = a / 2;
        else Np = a * 2;
    } else Np = a * 2;

    // Afiseaza raspunsul
    cout << Np;
    return 0;
}