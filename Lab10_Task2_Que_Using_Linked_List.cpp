#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class QueueType {
public:
    QueueType();             
    ~QueueType();            
    void MakeEmpty();        
    bool IsEmpty() const;    
    void Enqueue(int newItem); 
    void Dequeue();                 
    void Display() const;    

private:
    Node* front;
    Node* rear;
    int count;
};


QueueType::QueueType() {
    front = rear = nullptr;
    count = 0;
}


QueueType::~QueueType() {
    MakeEmpty();
}


void QueueType::MakeEmpty() {
    while (!IsEmpty()) {
        Dequeue();
    }
}

bool QueueType::IsEmpty() const {
    return front == nullptr;
}


void QueueType::Enqueue(int newItem) {
    Node* newNode = new Node;
    newNode->data = newItem;
    newNode->next = nullptr;

    if (IsEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}
void QueueType::Dequeue() {
    if (IsEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    count--;
}
void QueueType::Display() const {
    Node* current = front;
    while (current != nullptr) {
        cout << current->data << "\t";
        current = current->next;
    }
    cout << endl;
    cout << "Value of count = " << count << endl;
}


int main() {
    QueueType queue;

    cout << "Initial state:" << endl;
    queue.Display();

    cout << "\nEnqueue operations:" << endl;
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    queue.Enqueue(50);
    queue.Display();

    cout << "\nDequeue one item:" << endl;
    queue.Dequeue();
    queue.Display();

    return 0;
}
