#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("fileRead.txt");
    int numar1, numar2;

    file >> numar1 >> numar2;
    file.close();

    std::cout << "Suma numerelor: " << numar1 + numar2 << std::endl;
    std::cout << "Media Aritmetica: " << (numar1 + numar2) / 2.0 << std::endl;

    return 0;
}