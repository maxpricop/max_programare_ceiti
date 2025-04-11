#include <iostream>

int fib(int number) {
    if ((number == 1) || (number == 0)) return number;
    return fib(number - 1) + fib(number - 2);
}

int main() {
    int fibonacciNumber = 7;
    std::cout << fib(fibonacciNumber);

    return 0;
}