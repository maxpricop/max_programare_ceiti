#pragma once
#include <cstddef>
#include <functional>

class LinkedList {
	private:
		struct Node {
				int data;
				Node *next;

				Node(int data);
		};

		Node *head;
		std::size_t listSize;

	public:
		LinkedList();
		~LinkedList();

		void insertEnd(int data);
		void display() const;
		void displayIf(const std::function<bool(int)> &condition) const;
		std::size_t countIf(const std::function<bool(int)> &condition) const;
		int findMin() const;
		std::size_t removeAll(int value);

		void clear();
		bool empty() const noexcept { return listSize == 0; }
		std::size_t size() const noexcept { return listSize; }
};
