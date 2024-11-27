#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the polynomial linked list
struct Node {
    int coeff; // Coefficient of the term
    int exp;   // Exponent of the term
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the polynomial
void appendNode(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
        return;
    }
    struct Node* temp = *poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp1 = poly1;
    struct Node* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp > temp2->exp) {
            appendNode(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else if (temp1->exp < temp2->exp) {
            appendNode(&result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        } else { 
            int sumCoeff = temp1->coeff + temp2->coeff;
            appendNode(&result, sumCoeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // Append remaining terms of poly1
    while (temp1 != NULL) {
        appendNode(&result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    // Append remaining terms of poly2
    while (temp2 != NULL) {
        appendNode(&result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

// Function to print a polynomial
void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Main function
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Create first polynomial: 3x^3 + 5x^2 + 6
    appendNode(&poly1, 3, 3);
    appendNode(&poly1, 5, 2);
    appendNode(&poly1, 6, 0);

    // Create second polynomial: 4x^3 + 2x^1 + 1
    appendNode(&poly2, 4, 3);
    appendNode(&poly2, 2, 1);
    appendNode(&poly2, 1, 0);

    printf("First Polynomial: ");
    printPolynomial(poly1);

    printf("Second Polynomial: ");
    printPolynomial(poly2);

    // Add the two polynomials
    struct Node* result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return 0;
}
