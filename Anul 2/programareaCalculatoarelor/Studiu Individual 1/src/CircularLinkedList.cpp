#include "../include/linkedLists/CircularLinkedList.hpp"

CircularDoublyLinkedList::Node::Node(int data) : data(data), next(this), prev(this) {}

CircularDoublyLinkedList::CircularDoublyLinkedList() : tail(nullptr), listSize(0) {}
CircularDoublyLinkedList::~CircularDoublyLinkedList() { clear(); }

bool CircularDoublyLinkedList::push(int value, std::size_t position) {
	if (position > listSize) return false;

	Node *newNode = new Node(value);

	if (listSize == 0) {
		tail = newNode;
		listSize++;

		return true;
	}

	Node *head = tail->next;
	Node *oldNode = nullptr;

	if (position == 0) {
		oldNode = tail;
	} else {
		std::size_t insertPosition = position - 1;

		if (insertPosition <= listSize / 2) {
			oldNode = head;

			for (std::size_t i = 0; i < insertPosition; i++) {
				oldNode = oldNode->next;
			}
		} else {
			oldNode = tail;

			for (std::size_t i = listSize - 1; i > insertPosition; i--) {
				oldNode = oldNode->prev;
			}
		}
	}

	newNode->next = oldNode->next;
	newNode->prev = oldNode;

	oldNode->next->prev = newNode;
	oldNode->next = newNode;

	if (position == listSize) tail = newNode;

	listSize++;
	return true;
}

bool CircularDoublyLinkedList::pop(std::size_t position) {
	if (listSize == 0 || position >= listSize) return false;

	if (listSize == 1) {
		delete tail;

		tail = nullptr;
		listSize = 0;

		return true;
	}

	Node *head = tail->next;

	if (position == 0) {
		Node *newHead = head->next;

		tail->next = newHead;
		newHead->prev = tail;

		head->next = nullptr;
		head->prev = nullptr;
		delete head;

		listSize--;
		return true;
	} else if (position == listSize - 1) {
		Node *newTail = tail->prev;

		newTail->next = head;
		head->prev = newTail;

		tail->next = nullptr;
		tail->prev = nullptr;
		delete tail;

		tail = newTail;
		listSize--;

		return true;
	}

	Node *target = nullptr;

	if (position <= listSize / 2) {
		target = head;

		for (std::size_t i = 0; i < position; i++) {
			target = target->next;
		}
	} else {
		target = tail;

		for (std::size_t i = listSize - 1; i > position; i--) {
			target = target->prev;
		}
	}

	target->prev->next = target->next;
	target->next->prev = target->prev;

	delete target;
	listSize--;

	return true;
}

std::size_t CircularDoublyLinkedList::countElementsWithEqualNeighbors() const {
	if (listSize < 3 || tail == nullptr) return 0;

	std::size_t counter = 0;
	Node *currentNode = tail->next;

	for (std::size_t i = 0; i < listSize; ++i) {
		if (currentNode->prev->data == currentNode->next->data) ++counter;

		currentNode = currentNode->next;
	}

	return counter;
}

void CircularDoublyLinkedList::clear() noexcept {
	if (listSize == 0 || tail == nullptr) return;

	if (listSize == 1) {
		delete tail;

		tail = nullptr;
		listSize = 0;

		return;
	}

	Node *currentNode = tail->next;
	Node *endNode = tail;

	while (currentNode != endNode) {
		Node *next = currentNode->next;
		delete currentNode;

		currentNode = next;
	}

	endNode->next = nullptr;
	endNode->prev = nullptr;
	delete endNode;

	tail = nullptr;
	listSize = 0;
}
