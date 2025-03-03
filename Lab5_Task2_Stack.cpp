#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    // Constructor to initialize stack
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Push operation
    void Push(int value) {
        if (IsFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << "Pushed " << value << " into stack." << endl;
        }
    }

    // Pop operation
    void Pop() {
        if (IsEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
        } else {
            cout << "Popped " << arr[top--] << " from stack." << endl;
        }
    }

    // Top operation
    int Top() {
        if (IsEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Returning -1 to indicate empty stack
        } else {
            return arr[top];
        }
    }

    // IsEmpty operation
    bool IsEmpty() {
        return top == -1;
    }

    // IsFull operation
    bool IsFull() {
        return top == capacity - 1;
    }

    // Display the stack elements
    void Display() {
        if (IsEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;

    // Ask the user for the stack size
    cout << "Enter stack size: ";
    cin >> size;

    // Create stack of given size
    Stack stack(size);

    // Perform stack operations
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);

    // Display stack elements
    stack.Display();

    // Perform some pop operations
    stack.Pop();
    stack.Pop();

    // Display stack after popping
    stack.Display();

    // Check top of the stack
    cout << "Top of the stack: " << stack.Top() << endl;

    // Perform pop until stack is empty
    stack.Pop();
    stack.Pop();

    // Try to pop from an empty stack
    stack.Pop();

    return 0;
}
