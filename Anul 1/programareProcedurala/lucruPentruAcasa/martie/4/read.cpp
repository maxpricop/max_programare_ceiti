#include <fstream>
#include <iostream>

int main() {
    int sum = 0;
    short int number;
    std::ifstream file("1.txt");

    for (unsigned short i = 0; i < 10; i++) {
        file >> number;
        sum += number;
    }

    file.close();
    std::cout << "Suma este: " << sum;
    return 0;
}