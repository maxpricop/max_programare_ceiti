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

    // Insertion Sort
    for (unsigned i = 1; i < lungimeArray; i++) {
        int temp = array[i];
        int j = i - 1;

        // Mutăm elementele care sunt mai mari decât temp la dreapta
        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }

        // Inserăm elementul la poziția corectă
        array[j + 1] = temp;
    }

    // Afisarea array-ului sortat
    for (unsigned i = 0; i < lungimeArray; i++) {
        cout << array[i] << " ";
    };

    return 0;
};