#include <iostream>

using namespace std;

// Calculeaza suma a doar numerelor pozitive de pe diagonala principala
int main() {
    unsigned n, sumEven = 0;
    cout << "Introdu nr. de linii/coloane: "; cin >> n;
    int tablou[n][n];
    unsigned totalCells = n * n;

    for (int i = 0; i < totalCells; i++) {
        cout << "Introdu un numar: "; cin >> tablou[n][n];


    };


    return 0;
};