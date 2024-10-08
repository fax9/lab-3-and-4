#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

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

void deleteFromStart(Node **head) {
    if (*head == NULL) return;  

    Node *temp = *head;         
    *head = (*head)->next;      

    if (*head != NULL) {        
        (*head)->prev = NULL;   
    }

    delete temp;                
}

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

    cout << "List before deletion: ";
    printList(head);

    deleteFromStart(&head);

    cout << "List after deletion: ";
    printList(head);

    return 0;
}
