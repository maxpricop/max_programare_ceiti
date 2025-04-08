#include <iostream>
using namespace std;

void arrangeNumbers(int number1, int number2, int number3) {
    if (number1 > number2 && number1 > number3) {
        // Number 1 is the biggest

        // Number 2 is the middle number
        if (number2 > number3) cout << number3 << " " << number2 << " " << number1;
        // Number 3 is the middle number
        else cout << number2 << " " << number3 << " " << number1;
    } else if (number2 > number1 && number2 > number3) {
        // Number 2 is the biggest

        // Number 1 is the middle number
        if (number1 > number3) cout << number3 << " " << number1 << " " << number2;
        // Number 3 is the middle number
        else cout << number1 << " " << number3 << " " << number2;
    } else {
        // Number 3 is the biggest

        // Number 1 is the middle number
        if (number1 > number2) cout << number2 << " " << number1 << " " << number3;
        // Number 2 is the middle number
        else cout << number1 << " " << number2 << " " << number3;
    }
};

int main() {
    int nr1, nr2, nr3;

    cout << "Introdu numarul 1: ";
    cin >> nr1;
    cout << "Introdu numarul 2: ";
    cin >> nr2;
    cout << "Introdu numarul 3: ";
    cin >> nr3;

    arrangeNumbers(nr1, nr2, nr3);
    return 0;
}