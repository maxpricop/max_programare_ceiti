#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <limits>

unsigned countWays(unsigned topStair) {
	unsigned prev1 = 1;
	unsigned prev2 = 1;

	for (unsigned i = 2; i <= topStair; i++) {
		unsigned currentStair = prev1 + prev2;

		prev2 = prev1;
		prev1 = currentStair;
	}

	return prev1;
}

void ex2() {
	unsigned stairs = 0;
	std::cout << "Introdu numarul de trepte: ";

	if (!(std::cin >> stairs) || stairs <= 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "Valoare invalida. Trebuie un integer > 0.\n";
		return;
	}

	unsigned ways = countWays(stairs);
	std::cout << "Numarul de moduri de a urca cele " << stairs << " trepte este: " << ways << "\n";
}
