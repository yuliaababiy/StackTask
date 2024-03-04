#include <iostream>
using namespace std;

class Stack {
private:
    int* array;
    int size;
    int top;

public:
    Stack(int stackSize) : size(stackSize), top(-1) {
        array = new int[size];
    }

    ~Stack() {
        delete[] array;
    }

    void push(int value) {
        if (top < size - 1) {
            array[++top] = value;
            cout << "Pushed: " << value << endl;
        }
        else {
            cerr << "Stack Overflow: Cannot push element, the stack is full." << endl;
        }
    }

    int pop() {
        if (top >= 0) {
            cout << "Popped: " << array[top] << endl;
            return array[top--];
        }
        else {
            cerr << "Stack Underflow: Cannot pop element, the stack is empty." << endl;
            return -1;
        }
    }

    int peek() const {
        if (top >= 0) {
            cout << "Peek: " << array[top] << endl;
            return array[top];
        }
        else {
            cerr << "Peek: Stack is empty." << endl;
            return -1;
        }
    }
};

int main() {
    Stack myStack(5);

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    myStack.peek();

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();

    myStack.peek();

    myStack.push(40);
    myStack.push(50);

    myStack.peek();

    return 0;
}