#include "appendLine.hpp"
#include "fstream"
#include "iostream"
#include "string"
#include "vector"

void appendLine(const std::vector<std::string> &elements, const std::string &filename) {
    std::ofstream file(filename, std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error: cannot open file \"" << filename << "\"\n";
        return;
    }

    bool firstElement = true; // To prevent writing a space at the beginning of the document
    for (const auto &element : elements) {
        if (!firstElement) file << ' ';
        else firstElement = false;

        file << element;
    }

    file << '\n';
    file.close();
};
