#pragma once

class StaticStack {
	private:
		int topIndex;
		int arr[100];

	public:
		StaticStack();

		void push(int element);
		void pop();
		int top();
};