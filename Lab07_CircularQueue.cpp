#include <iostream>
using namespace std;
class QueType
{
public:
    QueType(int);
    ~QueType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enque(int);
    void Deque();
    int peek();
    void Display();

private:
    int rear, front;
    int *items;
    int maxQue;
};
QueType::QueType(int max)
{
    maxQue = max + 1;
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new int[maxQue];
}
QueType::~QueType()
{
    delete[] items;
}
void QueType::MakeEmpty()
{
    front = maxQue - 1;
    rear = maxQue - 1;
}
bool QueType::IsEmpty() const
{
    return (front == rear);
}
bool QueType::IsFull() const
{
    return ((rear + 1) % maxQue == front);
}
void QueType::Enque(int newItem)
{
    if (IsFull())
    {
        cout << "Que is Full!\n";
        return;
    }
    rear = (rear + 1) % maxQue;
    items[rear] = newItem;
    cout << "Enqued Item: " << newItem<<endl;
}
void QueType::Deque()
{
    if (IsEmpty())
    {
        cout << "Que is Empty!\n";
        return;
    }
    cout << "Dequed item:" << items[(front + 1) % maxQue] << endl;
    front = (front + 1) % maxQue;
}
int QueType::peek()
{
    if (IsEmpty())
    {
        cout << "Que is Empty, No front element!";
        return -1;
    }
    return items[(front + 1) % maxQue];
}
void QueType::Display()
{
    if (IsEmpty())
    {
        cout << "Que Is Empty!\n";
        return;
    }
    if (rear >= front)
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << items[i] << endl;
        }
    }
    else
    {
        for (int i = front + 1; i < maxQue; i++)
        {
            cout << items[i] << endl;
        }
    for (int i = 0; i <= rear; i++)
    {
        cout << items[i] << endl;
    }
    cout << endl;
}
}
int main()
{
    QueType q(5); // Que Capacity 5
    q.Enque(3);
    q.Enque(4);
    q.Enque(5);
    q.Enque(7);
    q.Enque(10);

    q.Display();

    q.Enque(78);

    q.Deque();
    q.Deque();
    q.Display();

    q.Deque();
    q.Deque();
    q.Deque();

    q.Display();
    
}
