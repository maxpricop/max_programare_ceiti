#include "../../types/Delivery.hpp"
#include "../../utils/files.hpp"
#include "../../utils/strings.hpp"
#include "deliveries.hpp"
#include "fstream"
#include "iostream"
#include "string"

void addNewDelivery(const std::string &filename) {
    std::vector<Delivery> deliveries = getAllDeliveries(filename);
    Delivery newDelivery{};

    std::cout << "Introduceti ID Livrare: ";
    std::cin >> newDelivery.id;

    for (const auto &delivery : deliveries) {
        if (delivery.id != newDelivery.id) continue;

        std::cout << "Deja exista o livrare cu acest ID.\n";
        return;
    }

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
