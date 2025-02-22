#include <iostream>
using namespace std;

int main() {
    unsigned arrayLength;
    cout << "Introdu lungimea arrayului: ";
    cin >> arrayLength;

    // Introducerea array-ului de utilizator
    int array[arrayLength];
    for (unsigned i = 0; i < arrayLength; i++) {
        cin >> array[i];
    }

    // Selection Sort
    for (unsigned i = 0; i < arrayLength - 1; i++) {
        unsigned minIndex = i; // Presupunem că primul element nesortat este minimul

        // Căutăm cel mai mic element în restul array-ului
        for (unsigned j = i + 1; j < arrayLength; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j; // Actualizăm indicele minimului
            }
        }

        // Schimbăm elementul minim găsit cu primul element nesortat
        if (minIndex != i) swap(array[i], array[minIndex]);
    }

    // Afișarea array-ului sortat
    for (unsigned i = 0; i < arrayLength; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
