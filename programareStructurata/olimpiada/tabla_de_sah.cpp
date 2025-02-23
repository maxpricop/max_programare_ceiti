#include <cmath>
#include <iostream>
using namespace std;

/* Conditie
Tabla de șah este constituită din n × m celule (pătrățele) colorate alternativ în alb și negru.
Totodată, celula din colțul stânga jos al tablei este vopsită în negru.
Determinați numărul total de celule ale tablei de șah, care sunt vopsite în negru.

Date de intrare. De la tastatură se citesc două numere naturale n și m, separate prin spațiu.
Date de ieşire. La ecran se va afișa naturalul Nc- numărul de celule ale tablei de șah, care sunt vopsite în negru.
Restricţii: : 1 ≤ n*m ≤ 2*10^18.*/
int main() {
    // Declararea variabilelor din conditie
    unsigned long long n, m, Nc;
    cin >> n >> m;

    // Previne introducerea numerelor care sunt inafara restrictiiei din conditie
    // Nu previn de introducerea a textului deoarace in conditie se zice ca sa introduce 2 numere naturale
    while (n < 1 || m < 1 || n > 2 * pow(10, 18) || m > pow(10, 18)) {
        cout << "Numerele trebuie sa fie intre 1 si 2 * 10^18. Reintrodu numarerele din nou: ";

        cin.clear(); // Previne erori cauzate de numere introduse ce sunt mai mari ca limita tipului unsigned in bytes
        cin >> n >> m;
    }

    // Calcularea numarerelor de celule negre. +1 schimba raspunsul doar pentru numerele impare. Cele pare raman corecte
    Nc = (n * m + 1) / 2;

    // Afisarea rezultatului
    cout << Nc << endl;
    return 0;
}