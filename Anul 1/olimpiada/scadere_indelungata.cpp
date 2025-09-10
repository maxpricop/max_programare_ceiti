#include <cmath>
#include <iostream>

using namespace std;
/* Conditie
Se dă un număr natural n. Din el se scade numărul egal cu lungimea numărului n.
Din rezultatul obținut se scade din nou numărul egal cu lungimea acestuia și așa mai departe.
Câte astfel de scăderi vor fi necesare pentru a obține numărul 0?

Date de intrare. Unica linie a intrării standard conține numărul natural n.

Date de ieşire. Ieșirea standard va conține pe o singură linie numărul necesar de scăderi pentru a obține numărul 0.
Restrictii: 1 ≤ n ≤ 10^16*/
int main() {
    unsigned long long n; // Declararea variabilei N, sa fie capabil sa incapa pana la 10^16.
    unsigned Ns = 0;      // Numarul de scaderi efectuate
    cin >> n;

    // Previne introducerea numarului care sunt inafara restrictiiei din conditie
    // Nu previn de introducerea a textului deoarace in conditie se zice ca sa introduce nuarul natural
    while (n < 1 || n > 10000000000000000) {
        cout << "Numarul trebuie sa fie intre 1 si 10^16. Reintrodu numarul din nou: ";

        cin.clear(); // Previne erori cauzate de numere introduse ce sunt mai mari ca limita tipului unsigned in bytes
        cin >> n;
    }

    // Scade continu numarul cu lungimea sa pana cand el devine 0
    while (n != 0) {
        // Afla lungimea folosind log10 a lui n, rotunjind numarul si adaugand 1
        unsigned lungime = floor(log10l(n)) + 1;

        n -= lungime; // Scade numarul cu lungimea sa
        Ns++;         // Mareste numarul de scaderi efectuate
    }

    // Afiseaza raspunsul
    cout << Ns;
    return 0;
}