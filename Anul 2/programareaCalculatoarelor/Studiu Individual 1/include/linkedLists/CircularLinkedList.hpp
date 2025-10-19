#pragma once
#include <cstddef>

class CircularDoublyLinkedList {
	private:
		struct Node {
			public:
				int data;
				Node *next;
				Node *prev;

				Node(int data);
		};

		Node *tail = nullptr;
		std::size_t listSize = 0;

	public:
		CircularDoublyLinkedList();
		~CircularDoublyLinkedList();

		Node *getHead() const noexcept { return tail ? tail->next : nullptr; }
		Node *getTail() const noexcept { return tail; }

		bool push(int value, std::size_t position);
		bool pop(std::size_t position);

		std::size_t countElementsWithEqualNeighbors() const;

		void clear() noexcept;
		bool isEmpty() const noexcept { return listSize == 0; }
		std::size_t size() const noexcept { return listSize; }
};
