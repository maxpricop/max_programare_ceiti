#include <iostream>

unsigned sumaSir(unsigned number) {
    if (number <= 1) return number;
    return sumaSir(number - 1) + number;
}

int main() {
    unsigned numar = 5;
    std::cout << sumaSir(numar);

    return 0;
}