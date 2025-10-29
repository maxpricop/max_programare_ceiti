#pragma once

class BinaryTree {
	private:
		struct Node {
			public:
				int data;
				Node *left;
				Node *right;

				Node(int nodeData);
		};

		Node *root;

	public:
		BinaryTree();
		~BinaryTree();

		void preorderTraversal() const;
		void inorderTraversal() const;
		void postorderTraversal() const;

		void insert(int data);
		bool search(int data) const;
		bool remove(int data);

		void clear();
		bool empty() const noexcept { return root == nullptr; }
};