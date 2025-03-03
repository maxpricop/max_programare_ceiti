#include <fstream>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    int number1, number2;

    inputFile >> number1 >> number2;
    inputFile.close();

    outputFile << number1 * number2 % 100;
    outputFile.close();

    return 0;
}