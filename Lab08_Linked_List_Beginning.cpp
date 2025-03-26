#include <iostream>
using namespace std;

struct node {
    int info;
    node* link;
};

node* head = NULL;
int count = 0;

void insertBeg(int data) {
    node* newNode = new node;
    newNode->info = data;
    newNode->link = head;
    head = newNode;
    count++;
}

void display() {
    node* current = head;
    while (current != NULL) {
        cout << current->info << " -> ";  // Use "->" instead of any special characters
        current = current->link;
    }
    cout << "NULL" << endl;
    cout << "Total Nodes: " << count << endl;
}

int main() {
    node* first = new node;
    node* second = new node;
    node* third = new node;

    first->info = 5;
    first->link = second;

    second->info = 10;
    second->link = third;

    third->info = 15;
    third->link = NULL;

    head = first;
    count = 3;

    cout << "Initial Linked List:" << endl;
    display();

    insertBeg(20);
    insertBeg(25);

    cout << "\nLinked List after Insertions:" << endl;
    display();

    return 0;
}
