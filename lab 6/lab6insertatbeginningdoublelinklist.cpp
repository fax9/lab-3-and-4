#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

// Function to insert at the beginning
void insertAtBeginning(Node **head, int newData) {
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = *head;  

    if (*head != NULL) {
        (*head)->prev = newNode;  
    }
    *head = newNode;  
}

// Function to print the list
void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL\n";
}

int main() {
    Node *head = NULL;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    cout << "Print list: ";
    printList(head);

    return 0;
}
