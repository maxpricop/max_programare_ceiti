#include "../include/exercises/Exercises.hpp"
#include <iostream>
#include <stack>

void ex7() {
	std::stack<int> stiva;

	std::cout << "Se ruleaza operatia push 3\n";
	stiva.push(3);

	std::cout << "Se ruleaza operatia push 7\n";
	stiva.push(7);

	std::cout << "Se ruleaza operatia pop. " << "Eliminat elementul: " << stiva.top() << '\n';
	stiva.pop();

	std::cout << "Se ruleaza operatia push 5\n";
	stiva.push(5);

	std::cout << "Se ruleaza operatia push 1\n";
	stiva.push(1);

	std::cout << "Elementul deasupra stivei: " << stiva.top() << '\n';
}