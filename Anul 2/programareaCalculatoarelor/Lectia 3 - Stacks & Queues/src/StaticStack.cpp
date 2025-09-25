#include "../include/stack/StaticStack.hpp"
#include <iostream>

StaticStack::StaticStack() : topIndex(-1) {};

void StaticStack::push(int element) {
	if (topIndex >= 99) {
		std::cerr << "Stack-ul este plin.\n";
		return;
	}

	topIndex++;
	arr[topIndex] = element;

	std::cout << "Adaugat cu succes elementul " << element << " deasupra stivei.\n";
}

void StaticStack::pop() {
	if (topIndex == -1) {
		std::cerr << "Stack-ul este gol";
		return;
	}

	topIndex--;
	std::cout << "Eliminat cu succes elementul " << arr[topIndex + 1] << '\n';
}

int StaticStack::top() {
	if (topIndex == -1) {
		std::cerr << "Stack-ul este gol";
		return 0;
	}

	return arr[topIndex];
}