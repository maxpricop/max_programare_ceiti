#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <queue>

void ex5() {
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

	std::cout << "Se ruleaza operatia EL. " << "Eliminat elementul: " << coada.front() << '\n';
	coada.pop();

	std::cout << "Se ruleaza operatia AD(8)\n";
	coada.push(8);

	std::cout << "Se ruleaza operatia AD(9)\n";
	coada.push(9);

	std::cout << "Se ruleaza operatia EL. " << "Eliminat elementul: " << coada.front() << '\n';
	coada.pop();

	std::cout << "Elementul din fata cozii: " << coada.front() << '\n';
}