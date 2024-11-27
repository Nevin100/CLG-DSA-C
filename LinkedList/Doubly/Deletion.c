#include <stdio.h>
#include <stdlib.h>

// Definition of the node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to delete a node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete a node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Function to delete a node in the middle
void deleteAtMiddle(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if ((*head)->next == NULL) { 
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* slow = *head;
    struct Node* fast = *head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow->prev != NULL) {
        slow->prev->next = slow->next;
    }
    if (slow->next != NULL) {
        slow->next->prev = slow->prev;
    }
    free(slow);
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("NULL <- ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Creating a doubly linked list
    head = createNode(10);
    head->next = createNode(20);
    head->next->prev = head;
    head->next->next = createNode(30);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(40);
    head->next->next->next->prev = head->next->next;

    printf("Initial List: ");
    printList(head);

    deleteAtBeginning(&head);
    printf("After deleting at beginning: ");
    printList(head);

    deleteAtMiddle(&head);
    printf("After deleting at middle: ");
    printList(head);

    deleteAtEnd(&head);
    printf("After deleting at end: ");
    printList(head);

    return 0;
}
