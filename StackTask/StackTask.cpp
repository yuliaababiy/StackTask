#include <iostream>
using namespace std;

class Stack {
private:
	int* array;
	int size;
	int top;

public:
	Stack(int stackSize) {
		size = stackSize;
		top = -1;
		array = new int[size];
	}

	bool push(int value) {
		if (top < size - 1) {
			// top = -1
			// top = 0
			// array[0] = 5
			// top = 1
			// array[1] = 10
			// top = 2
			// array[2] = 7
			array[++top] = value;
			cout << value << " was pushed" <<endl;
			return true;
		}
		else {
			cout << "Cannot push element because the stack is full" <<endl;
			return false;
		}
	}

	int pop() {
		if (top >= 0) {
			// 1 2 3, top = 2
			// pop першого елементу
			// top = 1
			// return 3
			// видаляє елемент і повертає його
			cout << array[top--] << " was popped" << endl;
			return array[top + 1];
		}
		else {
			cout << "Cannot pop element because the stack is empty" << endl;
			return -1;
		}
	}

	int peek() {
		if (top >= 0) {
			cout << "Peek element: " << array[top] << endl;
			return array[top];
		}
		else {
			cout << "Stack is empty" << endl;
			return -1;
		}
	}

	void printStack() {
		cout << "Your stack elements: " << endl;
		if (top == -1) {
			cout << "Stack is empty" << endl;
			return;
		}
		for (int i = 0; i <= top; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

// tests
void testPushAndPop() {
	Stack stack(2);
	stack.push(10);
	stack.push(20);
	//  10 20
	int popped1 = stack.pop();
	int popped2 = stack.pop();
	if (popped1 == 20 && popped2 == 10) {
		cout << "Push and pop test passed" << endl;
	}
	else {
		cout << "Push and pop test failed" << endl;
	}
}

void testPeek() {
	Stack stack(2);
	stack.push(10);
	stack.push(20);
	int peeked = stack.peek();
	if (peeked == 20) {
		cout << "Peek test passed" << endl;
	}
	else {
		cout << "Peek test failed" << endl;
	}
}

void testPushWhenFull() {
	Stack stack(2);
	stack.push(10);
	stack.push(20);
	if (stack.push(30) == false) {
		cout << "Push when full test passed" <<endl;
	}
	else {
		cout << "Push when full test failed" <<endl;
	}
}

void testPopWhenEmpty() {
	Stack stack(2);
	if (stack.pop() == -1) {
		cout << "Pop when empty test passed" << endl;
	}
	else {
		cout << "Pop when empty test failed" << endl;
	}
}

void testPeekWhenEmpty() {
	Stack stack(2);
	if (stack.peek() == -1) {
		cout << "Peek when empty test passed" << endl;
	}
	else {
		cout << "Peek when empty test failed" << endl;
	}
}

int main() {
	cout << "Enter stack size: " << endl;
	int stackSize;
	cin >> stackSize;
	Stack myStack(stackSize);

	int actionValue;
	cout << "Enter action you want to do: " << endl
		<< "1 - push into stack" << endl
		<< "2 - pop from stack" << endl
		<< "3 - peek from stack" << endl
		<< "4 - print all stack elements" << endl
		<< "5 - run tests" << endl
		<< "6 - exit" << endl;
	do {
		cout << "Your action: ";
		cin >> actionValue;
		switch (actionValue) {
		// if actionValue == 1 те саме що case:1
		case 1: {
			int pushOperationValue;
			cout << "Enter value you want to push" << endl;
			cin >> pushOperationValue;
			myStack.push(pushOperationValue);
			break;
		}
		case 2: {
			myStack.pop();
			break;
		}
		case 3: {
			myStack.peek();
			break;
		}
		case 4: {
			myStack.printStack();
			break;
		}
		case 5: {
			cout << "Running tests..." << endl;
			testPushAndPop();
			cout << "------------------------------------------------" << endl;
			testPeek();
			cout << "------------------------------------------------" << endl;
			testPushWhenFull();
			cout << "------------------------------------------------" << endl;
			testPopWhenEmpty();
			cout << "------------------------------------------------" << endl;
			testPeekWhenEmpty();
			cout << "------------------------------------------------" << endl;
			break;
		}
		case 6: {
			cout << "Exiting program" << endl;
			break;
		}
		default: {
			cout << "You entered a wrong option!" << endl;
			break;
		}
		}
	} while (actionValue != 6);

	return 0;
}
