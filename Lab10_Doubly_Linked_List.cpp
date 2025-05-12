
#include <iostream>
using namespace std;

struct node {
    int info;
    node* prev;
    node* next;
};

node* head = NULL;

void insert(int data) {
    node* newNode = new node;
    newNode->info = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

void delete_node() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
}

void display() {
    node* temp = head;
    cout << "Forward: ";
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseDisplay() {
    node* temp = head;

    if (temp == NULL) {
        cout << "Reverse: List is empty" << endl;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    cout << "Reverse: ";
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    cout << "After Insertions:" << endl;
    display();
    reverseDisplay();

    delete_node();

    cout << "\nAfter One Deletion:" << endl;
    display();
    reverseDisplay();

    insert(40);

    cout << "\nAfter Inserting 40 at Beginning:" << endl;
    display();
    reverseDisplay();

    return 0;
}

