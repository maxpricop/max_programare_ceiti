#include "../include/exercises/Exercises.hpp"
#include <iostream>

int getPrimeFactorsRecursively(unsigned n, int divisor) {
	if (n % divisor == 0) {
		std::cout << divisor << " ";
		return getPrimeFactorsRecursively(n / divisor, divisor);
	} else if (divisor * divisor <= n) {
		return getPrimeFactorsRecursively(n, divisor + 1);
	} else {
		if (n > 1) std::cout << n << " ";
		return 0;
	}
}

void primeFactors() {
	unsigned n;
	std::cout << "Introdu un numar intreg pozitiv: ";
	std::cin >> n;

	std::cout << "Factorii primi ai lui " << n << " sunt: ";
	getPrimeFactorsRecursively(n, 2);
}