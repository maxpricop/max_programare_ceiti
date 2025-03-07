#include <fstream>
#include <iostream>

int main() {
    std::ifstream file("numere.txt");
    short unsigned int n; // Nr. de pe prima linie
    int maxNumber, currentNumber;

    file >> n;

    file >> currentNumber;     // Citirea primului numar din sirul de numere
    maxNumber = currentNumber; // Setarea numarului maxim ca si primul numar

    // Loop prin toate numerele, incepe de la 1 pentru ca primul numar deja a fost citit mai sus
    for (unsigned short i = 1; i < n; i++) {
        file >> currentNumber;

        // Setarea numarului maxim daca se gaseste unul mai mare
        if (currentNumber > maxNumber) maxNumber = currentNumber;
    }

    std::cout << "Numarul maxim este: " << maxNumber;

    return 0;
}