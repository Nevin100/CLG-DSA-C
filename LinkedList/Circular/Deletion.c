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

// Function to insert a node at the end (helper for creating a list)
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Function to delete a node from the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. No deletion performed.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == *head) {
        // Only one node in the list
        free(temp);
        *head = NULL;
        return;
    }
    // Traverse to the last node
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    // Update links and free memory
    last->next = (*head)->next;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. No deletion performed.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == *head) {
        // Only one node in the list
        free(temp);
        *head = NULL;
        return;
    }
    // Traverse to the second last node
    struct Node* prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    // Update links and free memory
    prev->next = *head;
    free(temp);
}

// Function to delete a node from a specific position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. No deletion performed.\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    int count = 1;
    // Traverse to the desired position
    while (count < position && temp->next != *head) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (count != position) {
        printf("Invalid position! No deletion performed.\n");
        return;
    }
    // Update links and free memory
    prev->next = temp->next;
    free(temp);
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

    // Insert elements to create a list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    displayList(head);

    // Delete from the beginning
    printf("\nDeleting from the beginning:\n");
    deleteAtBeginning(&head);
    displayList(head);

    // Delete from the end
    printf("\nDeleting from the end:\n");
    deleteAtEnd(&head);
    displayList(head);

    // Delete from a specific position
    printf("\nDeleting from position 2:\n");
    deleteAtPosition(&head, 2);
    displayList(head);

    // Attempt to delete from an invalid position
    printf("\nDeleting from invalid position 10:\n");
    deleteAtPosition(&head, 10);
    displayList(head);

    return 0;
}
