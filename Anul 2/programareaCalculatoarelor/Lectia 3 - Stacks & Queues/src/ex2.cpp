#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <stack>

void ex2() {
	std::stack<int> stiva;
	stiva.push(10);
	stiva.push(5);
	stiva.push(4);

	std::cout << "Creata o stiva cu elementele 10, 5, 4.\n";
	std::cout << "Elemenetul deasupra stivei: " << stiva.top() << '\n';

	std::cout << "Se ruleaza operatia POP. " << "Eliminat elementul: " << stiva.top() << '\n';
	stiva.pop();

	std::cout << "Se ruleaza operatia PUSH(7).\n";
	stiva.push(7);

	std::cout << "Se ruleaza operatia POP. " << "Eliminat elementul: " << stiva.top() << '\n';
	stiva.pop();

	std::cout << "Se ruleaza operati POP. " << "Eliminat elementul: " << stiva.top() << '\n';
	stiva.pop();

	std::cout << "Se ruleaza operatia PUSH(9).\n";
	stiva.push(9);

	std::cout << "Elementul deasupra stivei: " << stiva.top() << '\n';
}