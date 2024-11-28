#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        // If the list is empty, the new node points to itself
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    // Traverse to the last node
    while (temp->next != *head) {
        temp = temp->next;
    }
    // Update links
    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        // If the list is empty, the new node points to itself
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    // Traverse to the last node
    while (temp->next != *head) {
        temp = temp->next;
    }
    // Update links
    temp->next = newNode;
    newNode->next = *head;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        // If the list is empty, the new node points to itself
        if (position == 1) {
            newNode->next = newNode;
            *head = newNode;
        } else {
            printf("Invalid position! List is empty.\n");
        }
        return;
    }
    if (position == 1) {
        // Insert at the beginning
        insertAtBeginning(head, data);
        return;
    }
    struct Node* temp = *head;
    int count = 1;
    // Traverse to the position just before the desired index
    while (count < position - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }
    if (count != position - 1) {
        printf("Invalid position! Position exceeds list size.\n");
        return;
    }
    // Update links
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function to demonstrate operations
int main() {
    struct Node* head = NULL;

    // Insert elements
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 5);
    displayList(head);

    insertAtEnd(&head, 20);
    insertAtEnd(&head, 25);
    displayList(head);

    insertAtPosition(&head, 15, 3);
    displayList(head);

    insertAtPosition(&head, 30, 7); // Invalid position
    displayList(head);

    return 0;
}
