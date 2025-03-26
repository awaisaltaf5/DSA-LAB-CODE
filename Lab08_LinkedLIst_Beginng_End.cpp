#include <iostream>
using namespace std;

struct node {
    int info;
    node* link;
};

node* head = NULL;
int count = 0;

// Function to insert a node at the beginning
void insertBeg(int data) {
    node* newNode = new node;
    newNode->info = data;
    newNode->link = head;
    head = newNode;
    count++;
}

// Function to insert a node at the end
void insertEnd(int data) {
    node* newNode = new node;
    newNode->info = data;
    newNode->link = NULL;
    if (head == NULL)
        head = newNode;
    else {
        node* temp = head;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newNode;
    }
    count++;
}

// Function to display the linked list
void display() {
    node* current = head;
    while (current != NULL) {
        cout << current->info << " -> ";
        current = current->link;
    }
    cout << "NULL" << endl;
    cout << "Total Nodes: " << count << endl;
}

int main() {
    // Creating an initial linked list with some elements
    node* first = new node;
    node* second = new node;
    node* third = new node;

    first->info = 10;
    first->link = second;

    second->info = 20;
    second->link = third;

    third->info = 30;
    third->link = NULL;

    head = first;
    count = 3;

    cout << "Initial Linked List:" << endl;
    display();

    // Insert one element at the beginning
    insertBeg(5);

    // Insert one element at the end
    insertEnd(40);

    cout << "\nLinked List after Insertions:" << endl;
    display();

    return 0;
}
