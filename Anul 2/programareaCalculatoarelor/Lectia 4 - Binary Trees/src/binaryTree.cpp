#include "../include/binaryTree/BinaryTree.hpp"
#include <iostream>
#include <stack>

BinaryTree::BinaryTree::Node::Node(int nodeData) : data(nodeData), left(nullptr), right(nullptr) {}

BinaryTree::BinaryTree() : root(nullptr) {}
BinaryTree::~BinaryTree() { clear(); }

void BinaryTree::preorderTraversal() const {
	if (root == nullptr) {
		std::cout << "Gol\n";
		return;
	}

	std::stack<const Node *> st;
	st.push(root);

	while (!st.empty()) {
		const Node *node = st.top();
		st.pop();

		if (!node) continue;
		std::cout << node->data << ' ';

		if (node->right) st.push(node->right);
		if (node->left) st.push(node->left);
	}

	std::cout << '\n';
}

void BinaryTree::inorderTraversal() const {
	if (root == nullptr) {
		std::cout << "Gol\n";
		return;
	}

	std::stack<const Node *> st;
	const Node *currentNode = root;

	while (currentNode != nullptr || !st.empty()) {
		while (currentNode != nullptr) {
			st.push(currentNode);
			currentNode = currentNode->left;
		}

		currentNode = st.top();
		st.pop();

		std::cout << currentNode->data << ' ';
		currentNode = currentNode->right;
	}

	std::cout << '\n';
}

void BinaryTree::postorderTraversal() const {
	if (root == nullptr) {
		std::cout << "Gol\n";
		return;
	}

	std::stack<const Node *> st;

	const Node *current = root;
	const Node *lastVisited = nullptr;

	while (current != nullptr || !st.empty()) {
		if (current != nullptr) {
			st.push(current);
			current = current->left;
			continue;
		}

		const Node *peek = st.top();

		// if right child exists and traversing node from left child, move to right child
		if (peek->right != nullptr && lastVisited != peek->right) current = peek->right;
		else {
			std::cout << peek->data << ' ';
			lastVisited = peek;
			st.pop();
		}
	}

	std::cout << '\n';
}

void BinaryTree::insert(int data) {
	if (root == nullptr) {
		root = new Node(data);
		return;
	}

	Node *currentNode = root;
	Node *parentNode = nullptr;

	while (currentNode != nullptr) {
		parentNode = currentNode;

		if (data < currentNode->data) currentNode = currentNode->left;
		else currentNode = currentNode->right;
	}

	if (data < parentNode->data) parentNode->left = new Node(data);
	else parentNode->right = new Node(data);
}

bool BinaryTree::search(int data) const {
	Node *currentNode = root;

	while (currentNode != nullptr) {
		if (data == currentNode->data) return true;
		else if (data < currentNode->data) currentNode = currentNode->left;
		else currentNode = currentNode->right;
	}

	return false;
}

bool BinaryTree::remove(int data) {
	Node *parent = nullptr;
	Node *node = root;

	// Find the node to remove
	while (node != nullptr && node->data != data) {
		parent = node;

		if (data < node->data) node = node->left;
		else node = node->right;
	}

	// Not found
	if (node == nullptr) return false;

	// If node has two children, find inorder successor (min in right subtree)
	if (node->left != nullptr && node->right != nullptr) {
		Node *succParent = node;
		Node *succ = node->right;

		while (succ->left != nullptr) {
			succParent = succ;
			succ = succ->left;
		}

		// Copy successor data to node and then delete successor instead
		node->data = succ->data;

		// Now remove successor node which has at most one child (right child)
		parent = succParent;
		node = succ;
	}

	// Node has at most one child now
	Node *child = (node->left != nullptr) ? node->left : node->right;

	if (parent == nullptr) root = child; // When node to be deleted is root
	else if (parent->left == node) parent->left = child;
	else parent->right = child;

	delete node;
	return true;
}

void BinaryTree::clear() {
	if (!root) return;

	std::stack<Node *> st;
	st.push(root);

	while (!st.empty()) {
		Node *node = st.top();
		st.pop();

		if (!node) continue;

		if (node->left) st.push(node->left);
		if (node->right) st.push(node->right);

		delete node;
	}

	root = nullptr;
}