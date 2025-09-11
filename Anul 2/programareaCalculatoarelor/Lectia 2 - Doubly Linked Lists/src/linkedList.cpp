#include "../include/linkedLists/LinkedList.hpp"
#include <iostream>
#include <stdexcept>

// Constructor of Node struct
LinkedList::Node::Node(int d) : data(d), next(nullptr), previous(nullptr) {}

// Constructor & Destructor for the Linked List Class
LinkedList::LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}
LinkedList::~LinkedList() { clear(); }

void LinkedList::insertAtStart(int data) {
	Node *newNode = new Node(data);

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		listSize++;

		return;
	}

	newNode->next = head;
	newNode->previous = nullptr;

	head->previous = newNode;
	head = newNode;

	listSize++;
}

void LinkedList::insertAtPosition(int data, unsigned position) {
	if ((position > listSize && position != 1) || position < 1) {
		throw std::runtime_error("Pozitia este invalida");
	}

	if (head == nullptr || position == 1) {
		insertAtStart(data);
		return;
	}

	Node *positionNode; // The node at the current position where a new one should be entered
	Node *newNode = new Node(data);

	// The position is in the first half of the list
	if (position < listSize / 2) {
		// start from beginning
		positionNode = head;

		for (unsigned i = 1; i < position; i++) {
			positionNode = positionNode->next;
		}
	} else {
		// Start from the end
		positionNode = tail;

		for (unsigned i = listSize; i > position; i--) {
			positionNode = positionNode->previous;
		}
	}

	positionNode->previous->next = newNode;
	newNode->previous = positionNode->previous;
	positionNode->previous = newNode;

	newNode->next = positionNode;
}

void LinkedList::insertAtEnd(int data) {
	Node *newNode = new Node(data);

	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		listSize++;

		return;
	}

	tail->next = newNode;
	newNode->previous = tail;
	tail = newNode;
	listSize++;
}

bool LinkedList::removeValue(int value) {
	if (head == nullptr) return false;

	Node *currentNode = head;

	while (currentNode != nullptr && currentNode->data != value) {
		currentNode = currentNode->next;
	}

	if (currentNode == nullptr) return false;

	// remove head
	if (currentNode->previous == nullptr) head = currentNode->next;
	else {
		currentNode->previous->next = currentNode->next;
		currentNode->next->previous = currentNode->previous;
	}

	delete currentNode;
	listSize--;

	return true;
}

bool LinkedList::removePosition(unsigned position) {
	if (head == nullptr) return false;
	if (position > listSize || position < 1) return false;

	Node *currentNode;

	// The position is in the first half of the list
	if (position < listSize / 2) {
		// start from beginning
		currentNode = head;

		for (unsigned i = 1; i < position; i++) {
			currentNode = currentNode->next;
		}
	} else {
		// Start from the end
		currentNode = tail;

		for (unsigned i = listSize; i > position; i--) {
			currentNode = currentNode->previous;
		}
	}

	if (currentNode->previous == nullptr) head = currentNode->next;
	else if (currentNode->next == nullptr) tail = currentNode->previous;
	else {
		currentNode->previous->next = currentNode->next;
		currentNode->next->previous = currentNode->previous;
	}

	delete currentNode;
	listSize--;

	return true;
}

void LinkedList::display() const {
	if (head == nullptr) {
		std::cout << "Lista este goala\n";
		return;
	}

	Node *currentNode = head;
	while (currentNode != nullptr) {
		std::cout << currentNode->data;

		if (currentNode->next) std::cout << ", ";
		currentNode = currentNode->next;
	}
	std::cout << '\n';
}

void LinkedList::clear() {
	Node *currentNode = head;
	while (currentNode != nullptr) {
		Node *next = currentNode->next;
		delete currentNode;
		currentNode = next;
	}

	head = nullptr;
	tail = nullptr;
	listSize = 0;
}
