#include <iostream>
using namespace std;

int main() {
    // Alocarea dinamica a celor 3 numere
    int *number1 = new int, *number2 = new int, *number3 = new int;

    cout << "Introdu 3 numere: ";
    cin >> *number1 >> *number2 >> *number3;

    // Determinarea numarului din mijloc
    if ((*number1 > *number2 && *number1 < *number3) || (*number1 < *number2 && *number1 > *number3)) {
        cout << "Elementul din mijloc este: " << *number1 << endl;
    } else if ((*number2 > *number1 && *number2 < *number3) || (*number2 < *number1 && *number2 > *number3)) {
        cout << "Elementul din mijloc este: " << *number2 << endl;
    } else {
        cout << "Elementul din mijloc este: " << *number3 << endl;
    }

    delete number1;
    delete number2;
    delete number3;

    return 0;
}