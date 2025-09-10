#include <iostream>

int sumaCifrelor(long numar) {
    int suma = 0;

    while (numar != 0) {
        suma += numar % 10;
        numar /= 10;
    }

    return suma;
}

int main() {
    long numar;

    std::cout << "Introdu numarul: ";
    std::cin >> numar;

    std::cout << "Suma cifrelor este: " << sumaCifrelor(numar);

    return 0;
}