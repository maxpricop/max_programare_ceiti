#include "../include/linkedLists/LinkedList.hpp"
#include <iostream>

// Constructor of Node struct
LinkedList::Node::Node(int d) : data(d), next(nullptr) {}

// Constructor & Destructor for the Linked List Class
LinkedList::LinkedList() : head(nullptr), listSize(0) {}
LinkedList::~LinkedList() { clear(); }

void LinkedList::insertAtStart(int data) {
	Node *newNode = new Node(data);

	newNode->next = head;
	head = newNode;
	listSize++;
}

void LinkedList::insertAtEnd(int data) {
	Node *newNode = new Node(data);

	if (head == nullptr) {
		head = newNode;
		listSize++;

		return;
	}

	Node *currentNode = head;
	while (currentNode->next != nullptr) {
		currentNode = currentNode->next;
	}

	currentNode->next = newNode;
	listSize++;
}

bool LinkedList::removeValue(int value) {
	if (head == nullptr) return false;

	Node *currentNode = head;
	Node *previousNode = nullptr;

	while (currentNode != nullptr && currentNode->data != value) {
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	if (currentNode == nullptr) return false;

	// remove head
	if (previousNode == nullptr) head = currentNode->next;
	else previousNode->next = currentNode->next;

	delete currentNode;
	listSize--;

	return true;
}

bool LinkedList::removePosition(unsigned position) {
	if (head == nullptr) return false;
	if (position > listSize || position < 1) return false;

	Node *currentNode = head;
	Node *previousNode = nullptr;

	for (unsigned i = 1; i < position; i++) {
		previousNode = currentNode;
		currentNode = currentNode->next;
	}

	// remove head
	if (previousNode == nullptr) head = currentNode->next;
	else previousNode->next = currentNode->next;

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
	listSize = 0;
}
