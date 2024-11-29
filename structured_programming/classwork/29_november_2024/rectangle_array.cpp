#include <iostream>

using namespace std;

// n linii, n coloane. Elementele de tip intreg input de la keyboard.
// Sa se afle suma elementelor, suma elementelor pare, produsul elementelor impare.

int main() {
    // N - linii, M - coloane
    unsigned n, m;
    int totalSum = 0, evenSum = 0, oddProduct = 1;

    cout << "Introdu nr. de linii: "; cin >> n;
    cout << "Introdu nr. de coloane: "; cin >> m;
    unsigned totalCells = n * m;
    int tablou[n][m];

    for (int i = 0; i < totalCells; i++) {
        cout << "Introdu un nr: "; cin >> tablou[0][i];

        totalSum += tablou[0][i];

        if (tablou[0][i] % 2 == 0) evenSum += tablou[0][i];
        else oddProduct *= tablou[0][i];
    };

    // cout << endl << endl;
    // for (int i = 0; i < totalCells; i++) {
    //     cout << "tablou[0][" << i << "] = " << tablou[0][i] << endl;
    // };

    cout << "Suma totala: " << totalSum << endl;
    cout << "Suma nr. pare: " << evenSum << endl;
    cout << "Produsul nr. impare: " << oddProduct << endl;

    return 0;
};