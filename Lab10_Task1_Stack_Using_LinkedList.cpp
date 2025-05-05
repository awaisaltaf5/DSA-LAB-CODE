#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int count;

public:
    Stack() {
        top = nullptr;
        count = 0;
    }

    ~Stack() {
        while (!IsEmpty()) {
            Pop();
        }
    }

    bool IsEmpty() const {
        return top == nullptr;
    }

    void Push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        count++;
    }

    void Pop() {
        if (IsEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
    }

void Display() const {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << "\t";
            current = current->next;
        }
        cout << endl;
        cout << "Value of count = " << count << endl;
    }
};

int main() {
    Stack stack;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    stack.Display();
    

    stack.Pop();
    cout << "After one pop:" << endl;
    stack.Display();

    while (!stack.IsEmpty()) {
        stack.Pop();
    }

    cout << "Trying to pop from an empty stack:" << endl;
    stack.Pop();

    return 0;
}
