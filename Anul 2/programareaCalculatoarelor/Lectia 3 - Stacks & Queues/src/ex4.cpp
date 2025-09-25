#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <queue>

void ex4() {
	std::queue<int> coada;
	coada.push(2);
	coada.push(1);

	std::cout << "Creata o coada cu elementele 2, 1.\n";
	std::cout << "Elementul din fata cozii: " << coada.front() << '\n';

	std::cout << "Se ruleaza operatia AD(5)\n";
	coada.push(5);

	std::cout << "Se ruleaza operatia EL. " << "Eliminat elementul: " << coada.front() << '\n';
	coada.pop();

	std::cout << "Se ruleaza operatia AD(4)\n";
	coada.push(4);

	std::cout << "Se ruleaza operatia EL. " << "Eliminat elementul: " << coada.front() << '\n';
	coada.pop();

	std::cout << "Se ruleaza operatia AD(7)\n";
	coada.push(7);

	std::cout << "Se ruleaza operatia EL. " << "Eliminat elementul: " << coada.front() << '\n';
	coada.pop();

	std::cout << "Se ruleaza operatia EL. " << "Eliminat elementul: " << coada.front() << '\n';
	coada.pop();

	std::cout << "Elementul din fata cozii: " << coada.front() << '\n';
}