#include <fstream>
#include <iostream>

int main() {
    int sum = 0;
    short int numbers[10];
    std::ifstream file("1.txt");

    for (unsigned short i = 0; i < 10; i++) {
        file >> numbers[i];
        sum += numbers[i];
    }

    file.close();
    std::cout << "Suma este: " << sum;
    return 0;
}