#include "../utils/files.hpp"
#include "beverages.hpp"
#include "iostream"
#include "string"

bool containsName(const std::string &line, const std::string &word) {
    std::string token = ' ' + word + ' ';
    return line.find(token) != std::string::npos;
}

void deleteBeverage(const std::string &filename) {
    std::string name;

    std::cout << "Introdu numele bauturii pe care vrei sa o stergi: ";
    std::cin >> name;

    std::vector<std::string> lines = readAllLines(filename);
    auto it = std::find_if(lines.begin(), lines.end(), [&](const std::string &l) { return containsName(l, name); });

    if (it == lines.end()) {
        std::cout << "Nu exista nici o bautura cu numele '" << name << "'\n";
        return;
    }

    lines.erase(it);
    std::cout << "Sters bautura '" << name << "'\n";

    writeAllLines(lines, filename);
}