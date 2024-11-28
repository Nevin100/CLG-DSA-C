#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the queue

// Queue structure
typedef struct Queue {
    int front;
    int rear;
    int size;
    int arr[MAX];
} Queue;

// Initialize the queue
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Check if the queue is full
int isFull(Queue* q) {
    return q->size == MAX;
}

// Enqueue operation: Add an element to the rear
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (q->front == -1) {
        // If the queue is empty, initialize front
        q->front = 0;
    }
    // Circular increment of rear
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    q->size++;
    printf("Enqueued: %d\n", value);
}

// Dequeue operation: Remove an element from the front
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->arr[q->front];
    // Circular increment of front
    q->front = (q->front + 1) % MAX;
    q->size--;
    // Reset front and rear if the queue becomes empty
    if (q->size == 0) {
        q->front = -1;
        q->rear = -1;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Peek operation: Get the front element without removing it
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }
    return q->arr[q->front];
}

// Display the queue elements
void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->arr[(q->front + i) % MAX]);
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
