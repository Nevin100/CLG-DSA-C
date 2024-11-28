#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Queue structure
typedef struct Queue {
    struct Node* front;
    struct Node* rear;
} Queue;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Enqueue operation: Add an element to the rear
void enqueue(Queue* q, int value) {
    struct Node* newNode = createNode(value);
    if (q->rear == NULL) {
        // If the queue is empty, both front and rear point to the new node
        q->front = newNode;
        q->rear = newNode;
    } else {
        // Add the new node at the rear and update the rear pointer
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", value);
}

// Dequeue operation: Remove an element from the front
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    // If the queue becomes empty, update rear to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    printf("Dequeued: %d\n", value);
    return value;
}

// Peek operation: Get the front element without removing it
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }
    return q->front->data;
}

// Display the queue elements
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    Queue q;
    initializeQueue(&q);

    // Perform queue operations
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);

    printf("Peek: %d\n", peek(&q));

    dequeue(&q);
    displayQueue(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    displayQueue(&q);

    dequeue(&q);
    dequeue(&q);
    displayQueue(&q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q); // Attempt to dequeue from an empty queue

    return 0;
}
