#include "../include/exercises/Exercises.hpp"
#include "../include/stack/StaticStack.hpp"
#include <iostream>

void ex1Static() {
	StaticStack stiva;
	stiva.push(1);
	stiva.push(2);
	stiva.push(3);

	std::cout << "Elemenetul deasupra stivei: " << stiva.top() << '\n';

	stiva.push(4);
	stiva.pop();
	stiva.pop();
	stiva.push(5);
	stiva.pop();
	stiva.pop();

	std::cout << "Elementul deasupra stivei: " << stiva.top() << '\n';
}