#include <iostream>

int calcVolume(int muchie) {
    return muchie * muchie * muchie;
}

int calcArea(int muchie) {
    return muchie * muchie * 6;
}

int calcPerimeter(int muchie) {
    return 12 * muchie;
}

int main() {
    int muchie;

    std::cout << "Introdu muchia cublui: ";
    std::cin >> muchie;

    std::cout << "Volumul cubului este: " << calcVolume(muchie) << " m^3 \n";
    std::cout << "Aria totala a cubului este: " << calcArea(muchie) << "m^2 \n";
    std::cout << "Perimeterul total al cubului este: " << calcPerimeter(muchie) << " m^2";

    return 0;
}