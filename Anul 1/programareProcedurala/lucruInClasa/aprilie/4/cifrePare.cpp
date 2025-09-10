#include <iostream>

int countEvenDigits(int number) {
    int counter = 0;

    while (number != 0) {
        int digit = number % 10;
        if (digit % 2 == 0) counter++;

        number /= 10;
    }

    return counter;
}

int main() {
    int numar;

    std::cout << "Introdu numarul: ";
    std::cin >> numar;

    std::cout << "Numarul total de cifre pare este " << countEvenDigits(numar);

    return 0;
}