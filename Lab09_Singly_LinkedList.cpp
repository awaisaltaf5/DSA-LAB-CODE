#include <iostream>
using namespace std;

// Structure for singly linked list node
struct node {
    int info;
    node* link;
};

// Global head pointer and node counter
node* head = NULL;
int count = 0;

// Function to insert nodes at the end (helper for testing deletions)
void insertEnd(int data) {
    node* newNode = new node;
    newNode->info = data;
    newNode->link = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        node* temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }

    count++;
}

// Function to delete from the beginning
void deleteBeg() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    node* ptr = head;
    head = head->link;
    delete ptr;
    count--;
}

// Function to delete from the end
void deleteEnd() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (head->link == NULL) {
        delete head;
        head = NULL;
        count--;
        return;
    }

    node* ptr = head;
    node* prev = NULL;

    while (ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }

    prev->link = NULL;
    delete ptr;
    count--;
}

// Function to delete from the middle (deletes node at count/2)
void deleteMiddle() {
    if (head == NULL || count < 3) {
        cout << "List too short to delete from middle.\n";
        return;
    }

    int mid = count / 2;
    node* ptr = head;
    node* prev = NULL;
    int c = 1;

    while (c != mid) {
        prev = ptr;
        ptr = ptr->link;
        c++;
    }

    prev->link = ptr->link;
    delete ptr;
    count--;
}

// Function to delete a node at a specific position (1-based index)
void deleteAtPosition(int pos) {
    if (pos < 1 || pos > count) {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 1) {
        deleteBeg();
        return;
    }

    node* ptr = head;
    node* prev = NULL;
    int c = 1;

    while (c < pos) {
        prev = ptr;
        ptr = ptr->link;
        c++;
    }

    prev->link = ptr->link;
    delete ptr;
    count--;
}

// Function to display the list
void display() {
    node* temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->info << " -> ";
        temp = temp->link;
    }
    cout << "NULL\n";
    cout << "Total Nodes: " << count << endl;
}

// Main function to demonstrate all deletions
int main() {
    // Insert test nodes
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50); // List: 10 -> 20 -> 30 -> 40 -> 50

    cout << "\nInitial List:\n";
    display();

    cout << "\nDeleting from Beginning:\n";
    deleteBeg();  // Deletes 10
    display();

    cout << "\nDeleting from End:\n";
    deleteEnd();  // Deletes 50
    display();

    cout << "\nDeleting from Middle:\n";
    deleteMiddle();  // Deletes 30 (middle of current list: 20 -> 30 -> 40)
    display();

    cout << "\nDeleting from Specific Position (Position 2):\n";
    deleteAtPosition(2);  // Deletes 40
    display();

    cout << "\nDeleting from Specific Position (Position 1):\n";
    deleteAtPosition(1);  // Deletes 20 (last remaining)
    display();

    return 0;
}
