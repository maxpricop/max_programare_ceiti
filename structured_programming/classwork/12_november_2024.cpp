#include <iostream>

using namespace std;

int main() {
    // Suma si produsul a primelor N numere
    // unsigned n, sum = 0, produs = 1;
    // cout << "Introdu un numar: "; cin >> n;

    // while (n > 0) {
    //     sum += n;
    //     produs *= n;
    //     n--;
    // };

    // cout << "Suma este: " << sum << endl;
    // cout << "Produsul este: " << produs << endl;

    // Nr este prim sau nu
    // unsigned n;
    // cout << "Introdu un numar: "; cin >> n;
    // unsigned i = n - 1;

    // while (i > 1) {
    //     if (n % i == 0) break;
    //     i--;
    // };

    // if (i == 0 || i == 1) cout << n << " este prim" << endl;
    // else cout << n << " nu este prim" << endl;


    unsigned long n, tempN;
    cout << "Introdu un numar: "; cin >> n;

    // nr Natural N, cu cel mult 9 cifre. Afisati cel mai din dreapta cifra para si cea mai din stanga cifra impara.
    // Daca n nu contine cifre pare se va afisa -1; Daca N nu contine cifra impare, se va afisa -2
    tempN = n;
    do {
        int cifra = tempN % 10;
        tempN /= 10;

        if (cifra % 2 == 0 || (cifra != 0 && n < 10)) {
            cout << "Cea mai din dreapta cifra para este: " << cifra << endl;
            break;
        };
        if (cifra == tempN) {
            cout << "-1" << endl;
            break;
        }
    } while (n);

    return 0;
};