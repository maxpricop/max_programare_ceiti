#include "printLine.hpp"
#include "iostream"
#include "string"

std::string printLine(std::string lineStart, std::string repeatedString, unsigned length, std::string lineEnd) {
    std::string line = lineStart;

    for (unsigned i = 0; i < length; i++) {
        line += repeatedString;
    }

    line += lineEnd;
    return line + '\n';
}
