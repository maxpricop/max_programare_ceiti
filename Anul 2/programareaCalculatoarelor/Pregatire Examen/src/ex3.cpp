#include "../include/exercises/Exercises.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

/**
 * Exercitiul 3
 * Se citeste un numar n de masini,
 * si un sir t=(t1, t2, ..., tn) de numere ce reprezinta timpii de reparare a fiecarei masini.
 * Elaborati un program ce calculeaza numarul maxim de masini care pot fi reparate in intervalul de timp T.
 */
void ex3() {
	size_t carCount = 0;
	while (true) {
		std::cout << "Introdu numarul de masini: ";

		if (!(std::cin >> carCount)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Input invalid\n\n";
			continue;
		}

		if (carCount <= 0) {
			std::cout << "Numarul de masini trebuie sa fie mai mare decat 0.\n\n";
			continue;
		}

		break;
	}

	unsigned long long int maxTime = 0;
	while (true) {
		std::cout << "Introdu intervalul total T (Timpul maxim de timp): ";

		if (!(std::cin >> maxTime)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Input invalid\n\n";
			continue;
		}

		if (maxTime < 0) {
			std::cout << "T trebuie sa fie nenegativ.\n\n";
			continue;
		}

		break;
	}

	std::vector<unsigned long long int> times(carCount);
	std::cout << "Introdu timpii de reparare (intregi, nenegativi):\n";
	for (size_t i = 0; i < carCount; ++i) {
		while (true) {
			std::cout << "T[" << i + 1 << "]: ";

			if (!(std::cin >> times[i])) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Input invalid\n";
				continue;
			}

			if (times[i] < 0) {
				std::cout << "Timpul trebuie sa fie nenegativ.\n";
				continue;
			}

			break;
		}
	}

	// std::sort(times.begin(), times.end());
	// Manual selection sort
	for (size_t i = 0; i < times.size(); ++i) {
		size_t min_index = i;

		for (size_t j = i + 1; j < times.size(); ++j) {
			if (times[j] < times[min_index]) min_index = j;
		}

		if (min_index != i) std::swap(times[i], times[min_index]);
	}

	unsigned long long int totalTimeSpent = 0;
	size_t repairedCarCount = 0;
	for (auto t : times) {
		if (totalTimeSpent + t <= maxTime) {
			totalTimeSpent += t;
			++repairedCarCount;
		} else {
			break;
		}
	}

	std::cout << "Numarul maxim de masini care pot fi reparate: " << repairedCarCount << '\n';
	if (repairedCarCount > 0) {
		std::cout << "Timpii selectati: ";
		for (size_t i = 0; i < repairedCarCount; ++i) {
			std::cout << times[i] << " ";
		}
		std::cout << '\n';
	}
}