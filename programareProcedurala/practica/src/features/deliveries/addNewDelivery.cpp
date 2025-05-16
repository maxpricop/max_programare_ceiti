#include "addNewDelivery.hpp"
#include "fstream"
#include "iomanip"
#include "iostream"
#include "string"
#include "types/Delivery.hpp"
#include "utils/appendLine.hpp"

void addNewDelivery(const std::string &filename) {
    Delivery newDelivery{};

    std::cout << "Introduceti ID Livrare: ";
    std::cin >> newDelivery.id;

    std::cout << "Introduceti ID bautura livrata: ";
    std::cin >> newDelivery.beverageId;

    std::cout << "Introduceti cantitatea livrata: ";
    std::cin >> newDelivery.quantityDelivered;

    appendLine({std::to_string(newDelivery.id), std::to_string(newDelivery.beverageId),
                std::to_string(newDelivery.quantityDelivered)},
               filename);
};
