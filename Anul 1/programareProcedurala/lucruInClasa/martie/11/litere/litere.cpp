#include <cctype>
#include <fstream>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    char currentCharacter;

    while (inputFile >> currentCharacter) {
        outputFile << (char)toupper(currentCharacter);
    }

    inputFile.close();
    outputFile.close();

    return 0;
}