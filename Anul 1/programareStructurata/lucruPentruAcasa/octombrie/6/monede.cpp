#include <iostream>

using namespace std;

// Determinarea cu cate monede de 5 si 3 se poate plati o suma de bani
int main() {
    /*Declararea variabilelor
    s = suma de bani
    monede3 = nr. de monede de 3 bani
    monede5 = nr. de monede de 5 bani*/
    int s, monede3, monede5;

    // Introducerea sumei de bani de utilizator
    cout << "Introdu suma de bani: ";
    cin >> s;

    // Determinarea numerelor de monede in baza monedelor de 3 bani
    if (s % 3 == 0) {
        monede3 = s / 3;
        monede5 = 0;
    } else if (s % 3 == 1) {
        monede3 = s / 3 - 3;
        monede5 = 2;
    } else {
        monede3 = s / 3 - 1;
        monede5 = 1;
    }

    // Afisarea rezultatelor
    if (monede3 < 0) {
        cout << "Nu se poate plati cu monede de 3 sau 5.";
    } else {
        cout << "Suma poate fi platita cu urmatoarele monezi:" << endl;
        cout << "Monede de 3: " << monede3 << endl;
        cout << "Monede de 5: " << monede5 << endl;
    }

    return 0;
}