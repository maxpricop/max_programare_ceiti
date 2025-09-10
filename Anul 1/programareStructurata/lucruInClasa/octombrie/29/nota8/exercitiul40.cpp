#include <cmath>
#include <iostream>

using namespace std;

/*Exercitiul 40 pagina 26 Turbo Pascal Culegere
Se dau numerele intregi m, n, p.
Sa se verifice daca ele sunt consecutive*/
int main() {
    // Declararea numerelor din conditie
    int m, n, p;

    // Introducerea numerelor de utilizator
    cout << "Introdu numarul m: ";
    cin >> m;
    cout << "Introdu numarul n: ";
    cin >> n;
    cout << "Introdu numarul p: ";
    cin >> p;

    // Declararea a variabile ce contin cel mai mare, mijlociu si cel mai mic numar
    int nrMax, nrMijlociu, nrMin;

    // Determinarea celui mai mare, mijlociu si cel mai mic numar dintre ele
    if (m <= n && m <= p) {
        nrMin = m;
        if (n <= p) {
            nrMijlociu = n;
            nrMax = p;
        } else {
            nrMijlociu = p;
            nrMax = n;
        }
    } else if (n <= m && n <= p) {
        nrMin = n;
        if (m <= p) {
            nrMijlociu = m;
            nrMax = p;
        } else {
            nrMijlociu = p;
            nrMax = m;
        }
    } else {
        nrMin = p;
        if (m <= n) {
            nrMijlociu = m;
            nrMax = n;
        } else {
            nrMijlociu = n;
            nrMax = m;
        }
    }

    // Afisarea rezultatelor
    if (abs(nrMax - nrMijlociu) == 1 && abs(nrMijlociu - nrMin) == 1) cout << "Numere sunt consecutive." << endl;
    else cout << "Numere nu sunt consecutive" << endl;

    return 0;
}