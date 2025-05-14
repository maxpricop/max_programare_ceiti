#include "features/displayBeverages.cpp"
#include "features/displayDeliveries.cpp"
#include <iostream>

void beverageOptions() {
    short unsigned userChoice;

    std::cout << "╔═══════════════════════════════════════════════════════╗\n";
    std::cout << "║                    Optiuni Bauturi                    ║\n";
    std::cout << "╠═══════════════════════════════════════════════════════╣\n";
    std::cout << "║ 1. Afiseaza toate bauturile                           ║\n";
    std::cout << "║ 2. Adauga o noua bautura                              ║\n";
    std::cout << "║ 3. Sterge o bautura                                   ║\n";
    std::cout << "║ 4. Editeaza o bautura                                 ║\n";
    std::cout << "║ 5. Afiseaza bauturile de un anumit tip                ║\n";
    std::cout << "║ 6. Afiseaza bautura cu cea mai mare si mica valoare   ║\n";
    std::cout << "║ 7. Afiseaza media pretului pe litru a bauturilor      ║\n";
    std::cout << "║ 8. Revina la meniul principal                         ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════╝\n";
    std::cout << "Alege o optiune: ";
    std::cin >> userChoice;

    switch (userChoice) {
        case 1: {
            displayBeverages("../data/Baut.txt");
            break;
        }
        default: {
            break;
        }
    }
}

void deliveryOptions() {
    short unsigned userChoice;

    std::cout << "╔═══════════════════════════════════════════════════════╗\n";
    std::cout << "║                    Optiuni Livrari                    ║\n";
    std::cout << "╠═══════════════════════════════════════════════════════╣\n";
    std::cout << "║ 1. Afiseaza toate livrarile                           ║\n";
    std::cout << "║ 2. Adauga o noua livrare                              ║\n";
    std::cout << "║ 3. Sterge o livrare                                   ║\n";
    std::cout << "║ 4. Editeaza o livrare                                 ║\n";
    std::cout << "║ 5. Creaza un rezumat al livrarilor                    ║\n";
    std::cout << "║ 6. Revina la meniul principal                         ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════╝\n";
    std::cout << "Alege o optiune: ";
    std::cin >> userChoice;

    switch (userChoice) {
        case 1: {
            displayDeliveries("../data/Livr.txt");
            break;
        }
        default: {
            break;
        }
    }
}

int main() {
    short unsigned userChoice;

    std::cout << "╔═══════════════════════════════════════════════════════╗\n";
    std::cout << "║                    Meniu Principal                    ║\n";
    std::cout << "╠═══════════════════════════════════════════════════════╣\n";
    std::cout << "║ 1. Optiuni bauturi                                    ║\n";
    std::cout << "║ 2. Optiuni livrari                                    ║\n";
    std::cout << "║ 3. Inchide meniul                                     ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════╝\n";
    std::cout << "Alege o optiune: ";
    std::cin >> userChoice;

    std::cout << "\n\n\n";

    switch (userChoice) {
        case 1: {
            beverageOptions();
            break;
        }
        case 2: {
            deliveryOptions();
            break;
        }
        case 3: {
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