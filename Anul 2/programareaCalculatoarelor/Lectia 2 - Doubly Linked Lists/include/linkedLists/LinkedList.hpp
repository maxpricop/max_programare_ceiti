#pragma once
#include <cstddef>

class LinkedList {
	private:
		struct Node {
				int data;
				Node *next;
				Node *previous;

				Node(int d);
		};

		Node *head;
		Node *tail;
		std::size_t listSize;

	public:
		LinkedList();
		~LinkedList();

		void insertAtStart(int data);
		void insertAtPosition(int data, unsigned position);
		void insertAtEnd(int data);
		bool removeValue(int value);
		bool removePosition(unsigned position);
		void display() const;

		void clear();
		bool empty() const noexcept { return listSize == 0; }
		std::size_t size() const noexcept { return listSize; }
};
