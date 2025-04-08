#include <iostream>
using namespace std;

bool isUnsignedPrime(unsigned number) {
    if (number < 2) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    for (int i = 3; i < number; i++) {
        if (number % i == 0) return false;
    }

    return true;
}

int main() {
    unsigned number;

    cout << "Introdu numarul: ";
    cin >> number;

    cout << "Numerele prime sunt:";
    for (int i = 2; i <= number / 2; i++) {
        if (number % i != 0) continue;
        if (isUnsignedPrime(i)) cout << " " << i;
    };

    if (isUnsignedPrime(number)) cout << " " << number;

    return 0;
}