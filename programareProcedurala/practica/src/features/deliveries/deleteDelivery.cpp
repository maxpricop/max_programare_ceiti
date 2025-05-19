#include "deliveries.hpp"
#include "iostream"
#include "string"
#include "utils/files.hpp"

unsigned getDeliveryId(const std::string &line) {
    auto spaceIndex = line.find(' '); // Index in the string of the first space

    // If there is no space in the whole line, return 0
    if (spaceIndex == std::string::npos) return 0;

    // Gets the string from the start of the line, up until the first space
    std::string idString = line.substr(0, spaceIndex);

    // Converts the string to an unsigned
    return std::stoul(idString);
}

void deleteDelivery(const std::string &filename) {
    unsigned id;

    std::cout << "Introdu ID-ul livrarii pe care vrei sa o stergi: ";
    std::cin >> id;

    std::vector<std::string> lines = readAllLines(filename);
    auto it = std::find_if(lines.begin(), lines.end(), [&](const std::string &l) { return getDeliveryId(l) == id; });

    if (it != lines.end()) {
        lines.erase(it);
        std::cout << "Sters livrarea cu ID-ul '" << id << "'\n";

        writeAllLines(lines, filename);
    } else std::cout << "Nu exista nici o livrare cu ID-ul '" << id << "'\n";
}