#include "createRepeatedString.hpp"
#include "string"

std::string createRepeatedString(std::string lineStart, std::string repeatedString, unsigned length,
                                 std::string lineEnd) {
    std::string line = lineStart;

    for (unsigned i = 0; i < length; i++) {
        line += repeatedString;
    }

    return line + lineEnd;
}
