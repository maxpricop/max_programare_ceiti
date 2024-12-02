#include <iostream>

using namespace std;

// Nr. 26
void ex1() {
    unsigned n;
    cout << "Introdu nr. de elemente ce in array: "; cin >> n;

    if (n >= 40) {
        n = 39;
        cout << "Nr. de elemente trebuie sa fie mai mic decat 40. Valoare introdusa a fost resetata la 39." << endl;
    }

    int H[n], sumPositive = 0;
    
    for (unsigned i = 0; i < n; i++) {
        cout << "Introdu H[" << i << "] = "; cin >> H[i];

        if (H[i] > 0) sumPositive += H[i];
    };

    cout << "Suma numerelor pozitive din acest array este: " << sumPositive << endl;
};

void ex2() {
    unsigned n, m;
    cout << "Introdu nr. de coloane: "; cin >> n;
    cout << "Introdu numarul de randuri: "; cin >> m;

    int T[n][m];

    for (unsigned column = 0; column < n; column++) {
        for (unsigned row = 0; row < m; row++) {
            cout << "Introdu T["<< column <<"][" << row << "] = "; cin >> T[column][row];
        }
    };
};

int main() {
    cout << "----- Problema 1 -----" << endl;
    ex1();

    return 0;
};