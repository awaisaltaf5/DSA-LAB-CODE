#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

class Stack
{
private:
    Node *top;
    int count;

public:
    Stack()
    {
        top = nullptr;
        count = 0;
    }

    ~Stack()
    {
        while (!IsEmpty())
        {
            Pop();
        }
    }

    bool IsEmpty() const
    {
        return top == nullptr;
    }

    void Push(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = top;

        if (top != nullptr)
        {
            top->prev = newNode;
        }

        top = newNode;
        count++;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        Node *temp = top;
        top = top->next;

        if (top != nullptr)
        {
            top->prev = nullptr;
        }

        delete temp;
        count--;
    }

    void Display() const
    {
        Node *temp = top;
        cout << "Stack (top to bottom): ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout << "Value of count = " << count << endl;
    }
};

int main()
{
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

    return 0;
}
