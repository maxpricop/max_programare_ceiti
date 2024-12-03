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

/*
Se consideră tabloul T[n][m] cu elemente numere întregi.
Să se compună un program care va înlocui în tabloul T elementele lui negative prin elementul maximal.
Tabloul modificat se va afişa pe ecran.

Conditia modificata de profesoara in clasa live, de scris asta in word
*/
void ex2() {
    unsigned n, m;
    cout << "Introdu nr. de randuri: "; cin >> n;
    cout << "Introdu numarul de coloane: "; cin >> m;

    int T[n][m], maxNumber;

    // Primul for loop pentru a introduce elementele si a determina numarul maxim.
    for (unsigned row = 0; row < n; row++) {
        for (unsigned column = 0; column < m; column++) {
            cout << "Introdu T["<< row <<"][" << column << "] = "; cin >> T[row][column];

            if (T[row][column] == T[0][0]) maxNumber = T[0][0];
            else if (T[row][column] > maxNumber) maxNumber = T[row][column];
        };
    };

    // Al doilea for loop pentru a inlocui numerele negative cu numarul maxim si a afisa arryul pe ecran.
    for (unsigned row = 0; row < n; row++) {
        for (unsigned column = 0; column < m; column++) {
            if (T[row][column] < 0) T[row][column] = maxNumber;

            cout << "\t" << T[row][column];
        };
        cout << endl;
    };
};

int main() {
    cout << "----- Problema 1 -----" << endl;
    ex1();

    cout << "----- Problema 2 -----" << endl;
    ex2();

    return 0;
};