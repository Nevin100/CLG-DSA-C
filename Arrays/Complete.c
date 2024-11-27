#include <stdio.h>

void insertElement(int arr[], int *n, int position, int element, int capacity) {
    if (*n >= capacity) {
        printf("Array is full, cannot insert an element.\n");
        return;
    }
    if (position < 0 || position > *n) {
        printf("Invalid position. Please enter a valid index.\n");
        return;
    }
    for (int i = *n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*n)++;
}

void deleteElement(int arr[], int *n, int position) {
    if (*n <= 0) {
        printf("Array is empty, cannot delete an element.\n");
        return;
    }
    if (position < 0 || position >= *n) {
        printf("Invalid position. Please enter a valid index.\n");
        return;
    }
    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void displayArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int capacity = 100; // Maximum capacity of the array
    int arr[100] = {10, 20, 30, 40, 50}; // Initial array
    int n = 5; // Current size of the array

    printf("Original array:\n");
    displayArray(arr, n);

    // Insert an element
    int position = 2;
    int element = 25;
    printf("\nInserting %d at position %d:\n", element, position);
    insertElement(arr, &n, position, element, capacity);
    displayArray(arr, n);

    // Delete an element
    position = 3;
    printf("\nDeleting element at position %d:\n", position);
    deleteElement(arr, &n, position);
    displayArray(arr, n);

    return 0;
}
