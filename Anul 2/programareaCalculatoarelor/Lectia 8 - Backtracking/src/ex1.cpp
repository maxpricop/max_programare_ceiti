#include "../include/exercises/Exercises.hpp"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

void writeToFile(const std::string &writeString, std::ofstream &outputFile, unsigned long long &counter) {
	for (size_t i = 0; i < writeString.size(); ++i) {
		if (i) outputFile << ' ';
		outputFile << writeString[i];
	}

	outputFile << '\n';
	counter++;
}

void backtrackString(int index, std::string &originalString, std::ofstream &outputFile, unsigned long long &counter) {
	if (index == originalString.size()) {
		writeToFile(originalString, outputFile, counter);
		return;
	}

	for (int i = index; i < originalString.size(); i++) {
		std::swap(originalString[index], originalString[i]);
		backtrackString(index + 1, originalString, outputFile, counter);
		std::swap(originalString[index], originalString[i]);
	}
}

void ex1() {
	short unsigned n;
	std::cout << "Introdu n: ";

	if (!(std::cin >> n) || n <= 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Valoare invalida. Trebuie un integer > 0.\n";
		return;
	}

	if (n > 9) {
		std::cout << "n prea mare pentru permutari cu cifre unice (max 9).\n";
		return;
	}

	const std::string filename = "perm.txt";
	std::ofstream outputFile(filename);

	if (!outputFile) {
		std::cout << "Eroare la deschiderea fisierului '" << filename << "' pentru scriere.\n";
		return;
	}

	unsigned long long count = 0;

	std::string originalString;
	originalString.reserve(n);

	// Generate the original string based on the value of n (for example n=3 -> "123")
	for (short unsigned i = 0; i < n; ++i) {
		originalString += char('1' + i);
	}

	backtrackString(0, originalString, outputFile, count);

	outputFile.close();

	auto cwd = std::filesystem::current_path();
	std::cout << "S-au generat " << count << " permutari. Salvat in: " << (cwd / filename) << "\n";
}