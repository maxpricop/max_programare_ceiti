#include <iostream>

// Cel mai mare divizor comun
int cmmdc(int number1, int number2) {
    if (number1 == number2) return number1;
    else if (number1 > number2) return cmmdc(number1 - number2, number2);
    return cmmdc(number1, number2 - number1);
}

int main() {
    int number1 = 82, number2 = 36;
    std::cout << cmmdc(number1, number2);

    return 0;
}