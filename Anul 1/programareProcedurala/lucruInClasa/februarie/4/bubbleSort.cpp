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

    // Bubble sort
    for (unsigned i = 0; i < lungimeArray; i++) {
        for (unsigned j = 0; j < lungimeArray - i - 1; j++) {
            if (array[j] > array[j + 1]) swap(array[j], array[j + 1]);
        }
    }

    // Afisarea array-ului sortat
    for (unsigned i = 0; i < lungimeArray; i++) {
        cout << array[i] << " ";
    };

    return 0;
};