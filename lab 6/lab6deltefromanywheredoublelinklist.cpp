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


void deleteNode(Node **head, int position) {
    if (*head == NULL) return;  

    Node *temp = *head;         

    
    if (position == 0) {
        *head = temp->next;     
        if (*head != NULL) {    
            (*head)->prev = NULL;
        }
        delete temp;
        return;
    }

    
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    
    if (temp == NULL) return;

    
    if (temp->next == NULL) {
        temp->prev->next = NULL;
    }
    
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    delete temp; 
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
    insertAtBeginning(&head, 40);

    cout << "Original List: ";
    printList(head);

    deleteNode(&head, 2);
    
    cout << "List after deleting node at position 2: ";
    printList(head);

    
    deleteNode(&head, 0);

    cout << "List after deleting head node: ";
    printList(head);

    deleteNode(&head, 1);

    cout << "List after deleting last node: ";
    printList(head);

    return 0;
}
