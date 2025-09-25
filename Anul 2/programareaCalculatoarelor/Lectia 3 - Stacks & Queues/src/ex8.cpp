#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <queue>

void ex8() {
	std::queue<int> coada;

	std::cout << "Se ruleaza operatia add 1\n";
	coada.push(1);

	std::cout << "Se ruleaza operatia add 2\n";
	coada.push(2);

	std::cout << "Se ruleaza operatia out. " << "Eliminat elementul: " << coada.front() << '\n';
	coada.pop();

	std::cout << "Se ruleaza operatia add 3\n";
	coada.push(3);

	std::cout << "Se ruleaza operatia add 4\n";
	coada.push(4);

	std::cout << "Elementul din fata cozii: " << coada.front() << '\n';
}