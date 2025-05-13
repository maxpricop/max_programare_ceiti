#include "features/displayBeverages.cpp"
#include <iostream>

void displayOptions() {
    std::cout << "=========================================================\n";
    std::cout << "Optiunile disponibile:\n";
    std::cout << "1.\tAfiseaza informatii despre bauturile racoritoare\n";
    std::cout << "2.\tAfiseaza informatii despre livrarile realizate\n";
    std::cout << "3.\tAdauga o noua bautura\n";
    std::cout << "4.\tAdauga o noua livrare\n";
    std::cout << "5.\tSterge o bautura\n";
    std::cout << "6.\tSterge o livrare\n";
    std::cout << "7.\tEditeaza o bautura\n";
    std::cout << "8.\tEditeaza o livrare\n";
    std::cout << "9.\tCreaza un rezumat al livrarilor\n";
    std::cout << "10.\tAfiseaza bauturile de un anumit tip\n";
    std::cout << "11.\tAfiseaza bautura cu cea mai mare si mica valoare\n";
    std::cout << "12.\tAfiseaza media pretului pe litru a bauturilor\n";
    std::cout << "13.\tInchide meniul\n";
}

int main() {
    short unsigned userChoice;

    // Shows the user all options which he can choose
    displayOptions();
    std::cout << "Optiunea aleasa: ";
    std::cin >> userChoice;

    // Handles the option chosen by the user
    switch (userChoice) {
        case 1: {
            displayBeverages("../data/Baut.txt");
            break;
        }
        case 13: {
            std::cout << "Ai inchis meniul.";
            break;
        }
        default: {
            std::cout << "Optiunea " << userChoice << " nu este valida.";
            break;
        }
    }

    return 0;
}