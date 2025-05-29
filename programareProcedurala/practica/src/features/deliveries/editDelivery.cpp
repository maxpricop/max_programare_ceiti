#include "../../types/Delivery.hpp"
#include "../../utils/files.hpp"
#include "../../utils/strings.hpp"
#include "deliveries.hpp"
#include "iostream"
#include "string"
#include "vector"

void editDelivery(const std::string &filename) {
    unsigned id;

    std::cout << "Introdu ID-ul livrarii pe care vrei sa o editezi: ";
    std::cin >> id;

    std::vector<Delivery> deliveries = getAllDeliveries(filename);

    for (auto &delivery : deliveries) {
        if (delivery.id != id) continue;

        std::cout << "Livrarea originala: " + deliveryToString(delivery) + '\n';
        std::cout << '\n';

        std::cout << "Modifica ID-ul livrarii: ";
        std::cin >> delivery.id;

        std::cout << "Modifica ID-ul bauturilor livrate: ";
        std::cin >> delivery.beverageId;

        std::cout << "Modifica cantitatea livrata: ";
        std::cin >> delivery.quantityDelivered;

        writeDeliveries(deliveries, filename);
        return;
    }

    std::cout << "Nu a fost gasita nici o livrare cu ID-ul '" << id << "'.\n";
}