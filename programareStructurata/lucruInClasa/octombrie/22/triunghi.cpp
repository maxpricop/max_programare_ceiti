#include <iostream>

using namespace std;

// Determinarea tipul unui triunghi in baza unghiurilor din el
int main() {
    // Declararea variabilelor cu unghiurile
    unsigned unghi1, unghi2, unghi3;

    // Introducerea valorilor unghiurilor de utilizator
    cout << "Introdu valoarea unghiului 1: ";
    cin >> unghi1;
    cout << "Introdu valoarea unghiului 2: ";
    cin >> unghi2;
    cout << "Introdu valoarea unghiului 3: ";
    cin >> unghi3;

    // Determinarea si afisarea tipului de triunghi
    if (unghi1 + unghi2 + unghi3 != 180) {
        cout << "Nu se poate crea un triughi din aceste numere";
    } else {
        if (unghi1 == unghi2 && unghi2 == unghi3) cout << "Triunghiul este echilateral";
        else if (unghi1 == unghi2 || unghi1 == unghi3 || unghi2 == unghi3) cout << "Triunghiul este isoscel";
        else cout << "Triunghiul este scalen";
    }

    return 0;
}