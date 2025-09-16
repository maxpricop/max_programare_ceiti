#include "../include/linkedLists/LinkedList.hpp"
#include <iostream>
#include <stdexcept>

LinkedList::Node::Node(int data) : data(data), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr), listSize(0) {}
LinkedList::~LinkedList() { clear(); }

void LinkedList::insertEnd(int data) {
	Node *newNode = new Node(data);

	if (!head) {
		head = newNode;
		++listSize;
		return;
	}

	Node *currentNode = head;
	while (currentNode->next) {
		currentNode = currentNode->next;
	}

	currentNode->next = newNode;
	++listSize;
}

void LinkedList::display() const {
	if (!head) {
		std::cout << "Lista este goala\n";
		return;
	}

	Node *currentNode = head;
	while (currentNode) {
		std::cout << currentNode->data;

		if (currentNode->next) std::cout << ", ";
		currentNode = currentNode->next;
	}

	std::cout << '\n';
}

void LinkedList::displayIf(const std::function<bool(int)> &condition) const {
	if (!head) {
		std::cout << "Lista este goala\n";
		return;
	}

	Node *currentNode = head;
	bool found = false;

	while (currentNode) {
		if (condition(currentNode->data)) {
			std::cout << currentNode->data;
			if (currentNode->next) std::cout << ", ";

			if (!found) found = true;
		}

		currentNode = currentNode->next;
	}

	if (!found) std::cout << "Nu exista elemente care indeplinesc conditia\n";
	else std::cout << '\n';
}

std::size_t LinkedList::countIf(const std::function<bool(int)> &condition) const {
	std::size_t counter = 0;

	Node *currentNode = head;
	while (currentNode) {
		if (condition(currentNode->data)) ++counter;
		currentNode = currentNode->next;
	}

	return counter;
}

int LinkedList::findMin() const {
	if (!head) throw std::runtime_error("Lista este goala - nu exista element minim.");

	Node *currentNode = head;
	int minElement = currentNode->data;

	while (currentNode) {
		if (currentNode->data < minElement) minElement = currentNode->data;
		currentNode = currentNode->next;
	}

	return minElement;
}

std::size_t LinkedList::removeAll(int value) {
	std::size_t removed = 0;

	while (head && head->data == value) {
		Node *temp = head;
		head = head->next;

		delete temp;
		listSize--;
		removed++;
	}

	if (!head) return removed;

	Node *currentElement = head;
	while (currentElement->next) {
		if (currentElement->next->data != value) {
			currentElement = currentElement->next;
			continue;
		}

		Node *temp = currentElement->next;
		currentElement->next = temp->next;

		delete temp;
		--listSize;
		++removed;
	}

	return removed;
}

void LinkedList::clear() {
	Node *currentElement = head;

	while (currentElement) {
		Node *next = currentElement->next;

		delete currentElement;
		currentElement = next;
	}

	head = nullptr;
	listSize = 0;
}
