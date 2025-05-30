#include "../../types/Delivery.hpp"
#include "../../utils/strings.hpp"
#include "deliveries.hpp"
#include "fstream"
#include "iostream"
#include "string"

void addNewDelivery(const std::string &filename) {
    Delivery newDelivery{};

    std::cout << "Introduceti ID Livrare: ";
    std::cin >> newDelivery.id;

    std::cout << "Introduceti ID bautura livrata: ";
    std::cin >> newDelivery.beverageId;

    std::cout << "Introduceti cantitatea livrata: ";
    std::cin >> newDelivery.quantityDelivered;

    std::string delivery = deliveryToString(newDelivery);
    std::ofstream file(filename, std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error: cannot open file \"" << filename << "\"\n";
        return;
    }

    file << delivery << '\n';
    file.close();

    std::cout << "Creat cu succes o noua livrare.\n";
};
