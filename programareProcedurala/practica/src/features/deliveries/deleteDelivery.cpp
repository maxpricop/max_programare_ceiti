#include "deliveries.hpp"
#include "iostream"
#include "string"
#include "utils/files.hpp"
#include "utils/findItemById.hpp"

void deleteDelivery(const std::string &filename) {
    unsigned id;

    std::cout << "Introdu ID-ul livrarii pe care vrei sa o stergi: ";
    std::cin >> id;

    std::vector<std::string> lines = readAllLines(filename);
    auto it = std::find_if(lines.begin(), lines.end(), [&](const std::string &l) { return findItemById(l) == id; });

    if (it != lines.end()) {
        lines.erase(it);
        std::cout << "Sters livrarea cu ID-ul '" << id << "'\n";

        writeAllLines(lines, filename);
    } else std::cout << "Nu exista nici o livrare cu ID-ul '" << id << "'\n";
}