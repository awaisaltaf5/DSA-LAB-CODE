#include <iostream>
using namespace std;

struct node {
    int info;
    node* link;
};

node* head = NULL;  
int count = 0;      
void insertend(int data)   {
    node* newNode = new node;
    newNode->info = data;
    newNode->link = NULL;
    if (head == NULL)
         head = newNode;
    else  
    {
       node* temp = head;
       while (temp->link != NULL)
           temp = temp->link;
        temp->link = newNode;    
    }
    count++;   
    }
    void display() {
        node* current = head;
        while (current != NULL) {
            cout << current->info << "\t";
            current = current->link;
        }
        cout << endl;
        cout << "Value of count = " << count << endl;
    }
    
    int main() {
        insertend(10);
        insertend(20);
        insertend(30);
        display(); 
        return 0;
    }
    
