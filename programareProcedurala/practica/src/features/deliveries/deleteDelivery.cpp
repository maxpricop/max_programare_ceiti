#include "../../types/Delivery.hpp"
#include "../../utils/files.hpp"
#include "../../utils/findItemById.hpp"
#include "deliveries.hpp"
#include "iostream"
#include "string"

void deleteDelivery(const std::string &filename) {
    unsigned id;

    std::cout << "Introdu ID-ul livrarii pe care vrei sa o stergi: ";
    std::cin >> id;

    std::vector<Delivery> deliveriesList = getAllDeliveries(filename);

    if (deliveriesList.empty()) {
        std::cerr << "Error: cannot open file \"" << filename << "\"\n";
        return;
    }

    auto it = std::find_if(deliveriesList.begin(), deliveriesList.end(), [&](const Delivery &d) { return d.id == id; });

    if (it == deliveriesList.end()) {
        std::cout << "Nu exista nici o livrare cu ID-ul \"" << id << "\"\n ";
        return;
    }

    deliveriesList.erase(it);
    std::cout << "Sters livrarea cu ID-ul \"" << id << "\"\n";

    writeDeliveries(deliveriesList, filename);
}