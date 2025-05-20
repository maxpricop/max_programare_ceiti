#include "deliveries.hpp"
#include "iostream"
#include "string"
#include "utils/files.hpp"
#include "utils/findItemById.hpp"
#include "vector"

void editDelivery(const std::string &filename) {
    unsigned id;

    std::cout << "Introdu ID-ul livrarii pe care vrei sa o editezi: ";
    std::cin >> id;

    std::vector<std::string> deliveries = readAllLines(filename);

    for (auto &delivery : deliveries) {
        if (findItemById(delivery) != id) continue;

        std::cout << "Livrarea originala: " + delivery + '\n';
        std::cout << '\n';

        unsigned newId;
        unsigned newBeverageId;
        double newQuantity;

        std::cout << "Modifica ID-ul livrarii: ";
        std::cin >> newId;

        std::cout << "Modifica ID-ul bauturilor livrate: ";
        std::cin >> newBeverageId;

        std::cout << "Modifica cantitatea livrata: ";
        std::cin >> newQuantity;

        delivery = std::to_string(newId) + ' ' + std::to_string(newBeverageId) + ' ' + std::to_string(newQuantity);

        writeAllLines(deliveries, filename);
        return;
    }

    std::cout << "Nu a fost gasita nici o livrare cu ID-ul '" << id << "'.\n";
}