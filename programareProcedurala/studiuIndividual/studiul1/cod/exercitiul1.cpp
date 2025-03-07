#include <iostream>
#include <string>
using namespace std;

int main() {
    unsigned n;
    cout << "Introdu numarul de elemente din array: ";
    cin >> n;

    string T[n];

    // Input la elementele array-ului de catre utilizator
    for (unsigned i = 0; i < n; i++) {
        cout << "Elementul " << i << ": ";
        cin >> T[i];
    }

    // Iterarea prin toate elementele array-ului
    for (unsigned i = 0; i < n; i++) {
        // Efectuarea selection sort pentru fiecare caracter a elementului din array
        unsigned lungimeString = T[i].length();
        for (unsigned indexCaracter = 0; indexCaracter < lungimeString - 1; indexCaracter++) {
            unsigned indexMin = indexCaracter;

            // Cauta cel mai mic caracter din string, incepand de la indexul caracterului pana la capat
            for (unsigned indexUrmator = indexCaracter + 1; indexUrmator < lungimeString; indexUrmator++) {
                if (T[i][indexUrmator] < T[i][indexMin]) indexMin = indexUrmator;
            }

            // Schimbarea caracterelor intre ele
            char temp = T[i][indexCaracter];
            T[i][indexCaracter] = T[i][indexMin];
            T[i][indexMin] = temp;
        }
    }

    // Afisarea array-ului sortat
    cout << "Array-ul sortat:";
    for (unsigned i = 0; i < n; i++) {
        cout << " " << T[i];
    }

    return 0;
}