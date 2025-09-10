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
    }

    // Selection Sort
    for (unsigned i = 0; i < lungimeArray - 1; i++) {
        unsigned minIndex = i; // Presupunem că primul element nesortat este minimul

        // Căutăm cel mai mic element în restul array-ului
        for (unsigned j = i + 1; j < lungimeArray; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j; // Actualizăm indicele minimului
            }
        }

        // Schimbăm elementul minim găsit cu primul element nesortat
        if (minIndex != i) swap(array[i], array[minIndex]);
    }

    // Afișarea array-ului sortat
    for (unsigned i = 0; i < lungimeArray; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
