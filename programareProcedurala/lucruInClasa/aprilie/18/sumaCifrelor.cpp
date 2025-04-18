#include <iostream>

// Suma cifrelor unui numar natural
unsigned sumaCifrelor(unsigned number) {
    if (number == 0) return number;
    return number % 10 + sumaCifrelor(number / 10);
}

int main() {
    unsigned numar = 69;
    std::cout << sumaCifrelor(numar);

    return 0;
}