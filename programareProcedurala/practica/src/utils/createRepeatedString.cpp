#include "createRepeatedString.hpp"
#include "iostream"
#include "string"

using namespace std;

string createRepeatedString(string lineStart, string repeatedString, unsigned length, string lineEnd) {
    string line = lineStart;

    for (unsigned i = 0; i < length; i++) {
        line += repeatedString;
    }

    return line + lineEnd;
}
