#include <stdio.h>

#define MAX 100 // Maximum size for the sparse matrix representation

// Function to convert a matrix to its sparse representation
void createSparseMatrix(int matrix[][MAX], int rows, int cols, int sparse[][3]) {
    int k = 1; // Start storing non-zero elements from the second row
    sparse[0][0] = rows; // Store number of rows
    sparse[0][1] = cols; // Store number of columns
    sparse[0][2] = 0;    // Initialize count of non-zero elements

    // Traverse the original matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
                sparse[0][2]++; // Increment non-zero count
            }
        }
    }
}

// Function to display a sparse matrix
void displaySparseMatrix(int sparse[][3]) {
    int count = sparse[0][2];
    printf("Sparse Matrix Representation:\n");
    printf("Row  Col  Value\n");
    for (int i = 0; i <= count; i++) {
        printf("%3d  %3d  %3d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}

// Function to restore a sparse matrix to its original form
void restoreMatrix(int sparse[][3], int matrix[][MAX]) {
    int rows = sparse[0][0];
    int cols = sparse[0][1];
    int count = sparse[0][2];

    // Initialize the original matrix with zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

    // Populate non-zero elements
    for (int i = 1; i <= count; i++) {
        matrix[sparse[i][0]][sparse[i][1]] = sparse[i][2];
    }
}

// Function to display a matrix
void displayMatrix(int matrix[][MAX], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function to demonstrate sparse matrix operations
int main() {
    int matrix[MAX][MAX], sparse[MAX][3], restored[MAX][MAX];
    int rows, cols;

    // Input the matrix dimensions
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &rows, &cols);

    // Input the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    displayMatrix(matrix, rows, cols);

    // Create sparse matrix representation
    createSparseMatrix(matrix, rows, cols, sparse);
    displaySparseMatrix(sparse);

    // Restore the matrix from sparse representation
    restoreMatrix(sparse, restored);
    printf("\nRestored Matrix:\n");
    displayMatrix(restored, rows, cols);

    return 0;
}
