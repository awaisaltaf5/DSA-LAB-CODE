#include <iostream>
using namespace std;

template <class T>
class QueueType
{
public:
    QueueType(int max);
    ~QueueType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(T newItem);
    void Dequeue();
    T peek() const;
    void Display() const;

private:
    int front, rear;
    T *items;
    int maxQue;
};

// Constructor
template <class T>
QueueType<T>::QueueType(int max)
{
    maxQue = max;
    front = -1;
    rear = -1;
    items = new T[maxQue];
}

// Destructor
template <class T>
QueueType<T>::~QueueType()
{
    delete[] items;
}

// Make queue empty
template <class T>
void QueueType<T>::MakeEmpty()
{
    front = -1;
    rear = -1;
}

// Check if queue is empty
template <class T>
bool QueueType<T>::IsEmpty() const
{
    return (front == -1 || front > rear);
}

// Check if queue is full
template <class T>
bool QueueType<T>::IsFull() const
{
    return (rear == maxQue - 1);
}

// Enqueue function
template <class T>
void QueueType<T>::Enqueue(T newItem)
{
    if (IsFull())
    {
        cout << "Queue is full. Cannot enqueue " << newItem << endl;
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    items[rear] = newItem;
}

// Dequeue function
template <class T>
void QueueType<T>::Dequeue()
{
    if (IsEmpty())
    {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    front++;
    if (front > rear)
    { 
        front = -1;
        rear = -1;
    }
}

// Peek function
template <class T>
T QueueType<T>::peek() const
{
    if (IsEmpty())
    {
        cout << "Queue is empty. No front element." << endl;
        return T(); // Return default value
    }
    return items[front];
}

// Display queue elements
template <class T>
void QueueType<T>::Display() const
{
    if (IsEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << items[i] << " ";
    cout << endl;
}

// Main function
int main()
{
    QueueType<int> queueInt(5); 

    queueInt.Enqueue(19);
    queueInt.Enqueue(20);
    queueInt.Enqueue(30);
    queueInt.Enqueue(15);
    queueInt.Enqueue(60);
    queueInt.Display();
    cout << "\nFront element: " << queueInt.peek() << endl;
    queueInt.Dequeue();
    cout << "\n After Dequeue of 1 Element:";
    queueInt.Display();

    queueInt.Dequeue();
    queueInt.Dequeue();
    queueInt.Dequeue();
    queueInt.Display();
    cout << "\nAfter Deque of all Elements:\n";
    queueInt.Dequeue();

    queueInt.Display();

    return 0;
}
