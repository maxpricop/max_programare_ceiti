#include "../include/exercises/Exercises.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <limits>
#include <vector>

/**
 * Exercitiul 2
 * Se citeste un sir de n numere intregi.
 * Elaborati un program ce va alege din sir un numar maxim de elemente
 * astfel incat produsul lor sa fie maxim.
 *
 * De exemplu pentru n=5 si sirul 3, -4, 2, -5, -8
 * se vor alege 3, 2, -5, -8.
 */
void ex2() {
	size_t length = 0;
	while (true) {
		std::cout << "Introdu lungimea sirului: ";

		if (!(std::cin >> length)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Input invalid\n\n";
			continue;
		}

		if (length == 0) {
			std::cout << "Lungimea sirului trebuie sa fie mai mare decat 0.\n\n";
			continue;
		}

		break;
	}

	std::vector<int> numbers(length);
	std::cout << "Introdu cele " << length << " numere intregi:\n";
	for (size_t i = 0; i < length; ++i) {
		std::cout << "Numarul " << i + 1 << ": ";
		std::cin >> numbers[i];
	}

	std::vector<int> chosenNumbers;
	int negativeCount = 0;
	int zeroCount = 0;
	int smallestNegative = std::numeric_limits<int>::min();

	for (int number : numbers) {
		if (number > 0) chosenNumbers.push_back(number);
		else if (number < 0) {
			negativeCount++;
			chosenNumbers.push_back(number);

			if (number > smallestNegative) smallestNegative = number;

		} else zeroCount++;
	}

	if (negativeCount % 2 != 0) {
		// remove the negative with smallest absolute impact (the largest negative, i.e. closest to zero)
		auto it = std::find(chosenNumbers.begin(), chosenNumbers.end(), smallestNegative);

		if (it != chosenNumbers.end()) {
			if (chosenNumbers.size() > 1) chosenNumbers.erase(it);
			else if (zeroCount > 0) {
				chosenNumbers.clear();
				chosenNumbers.push_back(0);
			}
		}
	}

	// If nothing was chosen (e.g. all zeros or all removed), select a zero if available,
	// otherwise pick the maximum element (best single choice)
	if (chosenNumbers.empty()) {
		if (zeroCount > 0) chosenNumbers.push_back(0);
		else if (!numbers.empty()) {
			int maxElem = numbers[0];
			for (int num : numbers) {
				if (num > maxElem) maxElem = num;
			}

			chosenNumbers.push_back(maxElem);
		}
	}

	std::cout << "Produsul maxim este: ";
	long long product = 1;
	for (int number : chosenNumbers) {
		product *= number;
	}
	std::cout << product << '\n';

	std::cout << "Numerele alese sunt: ";
	for (int number : chosenNumbers) {
		std::cout << number << " ";
	}
}