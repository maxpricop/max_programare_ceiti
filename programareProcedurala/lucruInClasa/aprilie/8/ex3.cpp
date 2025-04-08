#include <iostream>
using namespace std;

int maxNumber(int number1, int number2) {
    if (number1 > number2) return number1;
    return number2;
}

int main() {
    int nr1, nr2;

    cout << "Introdu numarul 1: ";
    cin >> nr1;
    cout << "Introdu numarul 2: ";
    cin >> nr2;

    cout << "Numarul cel mai mare este: " << maxNumber(nr1, nr2);

    return 0;
}