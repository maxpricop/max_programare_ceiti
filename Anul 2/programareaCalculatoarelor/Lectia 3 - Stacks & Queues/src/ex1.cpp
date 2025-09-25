#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <stack>

void ex1() {
	std::stack<int> stiva;
	stiva.push(1);
	stiva.push(2);
	stiva.push(3);

	std::cout << "Creata o stiva cu elementele 1, 2, 3.\n";
	std::cout << "Elemenetul deasupra stivei: " << stiva.top() << '\n';

	std::cout << "Se ruleaza operatia AD(4)\n";
	stiva.push(4);

	std::cout << "Se ruleaza operatia EL. " << "Eliminat elementul: " << stiva.top() << '\n';
	stiva.pop();

	std::cout << "Se ruleaza operatia EL. " << "Eliminat elementul: " << stiva.top() << '\n';
	stiva.pop();

	std::cout << "Se ruleaza operatia AD(5)\n";
	stiva.push(5);

	std::cout << "Se ruleaza operatia EL. " << "Eliminat elementul: " << stiva.top() << '\n';
	stiva.pop();

	std::cout << "Se ruleaza operatia EL. " << "Eliminat elementul: " << stiva.top() << '\n';
	stiva.pop();

	std::cout << "Elementul deasupra stivei: " << stiva.top() << '\n';
}