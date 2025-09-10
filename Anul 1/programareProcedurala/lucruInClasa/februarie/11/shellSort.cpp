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

    // Shell Sort
    for (unsigned spatiu = lungimeArray / 2; spatiu > 0; spatiu /= 2) {
        for (unsigned i = spatiu; i < lungimeArray; i++) {
            int temp = array[i];
            int j = i;

            for (j; j >= spatiu && array[j - spatiu] > temp; j -= spatiu) {
                array[j] = array[j - spatiu];
            }
            array[j] = temp;
        }
    }

    // Afisarea array-ului sortat
    for (unsigned i = 0; i < lungimeArray; i++) {
        cout << array[i] << " ";
    };

    return 0;
};