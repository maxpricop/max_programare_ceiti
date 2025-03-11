#include <fstream>
#include <iostream>

int main() {
    std::ifstream inputFile;
    std::ofstream outputFile;

    int numberCount = 0, charCount = 0;
    char currentChar;

    inputFile.open("input.txt");
    while (inputFile.get(currentChar)) {
        if (isdigit(currentChar)) numberCount++;
        else if (isalpha(currentChar)) charCount++;
    }
    inputFile.close();

    outputFile.open("output.txt");
    outputFile << charCount << "\n" << numberCount;
    outputFile.close();

    return 0;
}