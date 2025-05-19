#include "files.hpp"
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

std::vector<std::string> readAllLines(const std::string &filename) {
    std::ifstream file(filename);

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

void writeAllLines(const std::vector<std::string> &lines, const std::string &filename) {
    std::ofstream file(filename);

    for (auto &line : lines) {
        file << line << '\n';
    }

    file.close();
}