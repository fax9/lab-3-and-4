#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};
void insertAtEnd(Node **head, int newData)
{
    // Create a new node
    Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Otherwise, traverse to the last node
    Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    // Adjust pointers for the new node
    last->next = newNode;
    newNode->prev = last;
}

void printreverse(Node *&head)
{
    if (head == NULL)
        return;
    printreverse(head->next);
    cout << head->data << "-> ";
}
int main()
{
    Node *head = NULL;
    insertAtEnd(&head, 10);
     insertAtEnd(&head, 20);
     insertAtEnd(&head, 30);
    printreverse(head);
    return 0;
}
