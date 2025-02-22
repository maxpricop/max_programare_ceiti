#include <iostream>
using namespace std;

int main() {
    unsigned lungimeArray;
    cout << "Introdu lungimea arrayului: ";
    cin >> lungimeArray;

    // Introducerea array-ului de utilizator
    int array[lungimeArray];
    for (unsigned i = 0; i < lungimeArray; i++) {
        cin >> array[i];
    };

    // Schimbarea valorilor
    bool change = false;
    do {
        change = false;

        // Iterarea prin tot array-ul
        for (unsigned i = 0; i < lungimeArray; i++) {

            // Daca se gaseste o valoare unde indexul mai mic e mai mare ca urmatoarea
            if (array[i] > array[i + 1]) {
                // Schimbarea valorilor intre ele
                swap(array[i], array[i + 1]);

                change = true;
            }
        }

    } while (change);

    // Afisarea array-ului sortat
    for (unsigned i = 0; i < lungimeArray; i++) {
        cout << array[i] << " ";
    };

    return 0;
};