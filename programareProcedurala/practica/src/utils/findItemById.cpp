#include "findItemById.hpp"
#include "string"

unsigned findItemById(const std::string &line) {
    // Index of the first space in the string
    auto spaceIndex = line.find(' ');

    // If there is no space in the whole line, return 0
    if (spaceIndex == std::string::npos) return 0;

    // Gets the string from the start of the line, up until the first space
    std::string idString = line.substr(0, spaceIndex);

    // Converts the string to an unsigned
    return std::stoul(idString);
}
