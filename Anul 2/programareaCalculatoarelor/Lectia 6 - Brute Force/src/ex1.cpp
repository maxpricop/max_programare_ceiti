#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <utility>
#include <vector>

bool isPrime(long long number) {
	if (number < 2) return false;
	if (number % 2 == 0) return number == 2;
	if (number % 3 == 0) return number == 3;

	for (long long divisor = 5; divisor * divisor <= number; divisor += 6) {
		if (number % divisor == 0 || number % (divisor + 2) == 0) return false;
	}

	return true;
}

void ex1() {
	long long start;
	long long end;

	std::cout << "Introdu inceputul intervalului: ";
	std::cin >> start;

	std::cout << "Introdu sfarsitul intervalului: ";
	std::cin >> end;

	if (start > end) std::swap(start, end);

	if (end < 2) {
		std::cout << "Intervalul nu are nici un numar prim.\n";
		return;
	}

	std::vector<long long> primeNumbers;

	for (long long i = start; i <= end; i++) {
		if (isPrime(i)) primeNumbers.push_back(i);
	}

	std::cout << "Numerele prime:";

	for (auto number : primeNumbers) {
		std::cout << ' ' << number;
	}
}