#include <iostream>
using namespace std;

// Structure for a node in the linked list
struct Node {
    int id;         // Integer value
    float value;    // Float value
    Node* link;     // Pointer to next node
};

// Head pointer for the list
Node* head = NULL;

// Function to insert a node at the end of the list
void insert(int id, float val) {
    Node* newNode = new Node;
    newNode->id = id;
    newNode->value = val;
    newNode->link = NULL;

    // If list is empty, new node becomes head
    if (head == NULL) {
        head = newNode;
    } else {
        // Traverse to the end of the list
        Node* temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode; // Link new node at the end
    }
}

// Function to display all nodes in the list
void display() {
    Node* temp = head;
    cout << "\nLinked List Records:\n";
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Value: " << temp->value << endl;
        temp = temp->link;
    }
}

int main() {
    int id;
    float val;

    cout << "Enter 6 records (Integer ID and Float Value):\n";
    for (int i = 1; i <= 6; i++) {
        cout << "Record " << i << ":\n";
        cout << "Enter ID (int): ";
        cin >> id;
        cout << "Enter Value (float): ";
        cin >> val;
        insert(id, val);
    }

    // Display all inserted records
    display();

    return 0;
}
