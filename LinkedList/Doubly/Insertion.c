#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* createNode(int data){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if(!newNode){
    printf("Memory cant be allocated!!\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void InsertionBeg(struct Node** head, int data){
  struct Node* newNode = createNode(data);
  if(*head == NULL){
    *head = newNode;
    return;
  }
  newNode->next = *head;
  (*head)->prev = newNode;
  *head = newNode;
}

void InsertionEnd(struct Node** head, int data){
  struct Node* newNode = createNode(data);
  if(*head == NULL){
    *head = newNode;
    return;
  }
  struct Node* temp = *head;
  while(temp->next != NULL){
    temp = temp->next;
  }

  temp->next = newNode;
  newNode->prev = temp;
}

void InsertionMiddle(struct Node** head, int data){
  if(*head ==NULL ){
    *head = createNode(data);
    return;
  }
  struct Node* slow = *head;
  struct Node* fast = *head;
  while(fast->next!=NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  struct Node* newNode = createNode(data);
  newNode->next = slow->next;
  newNode->prev = slow;
  if( slow->next != NULL ){
    slow->next->prev = newNode;
  }
  slow->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    printf("NULL <- ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    InsertionEnd(&head, 10);
    InsertionEnd(&head, 20);
    InsertionEnd(&head, 30);
    printf("Initial List: ");
    printList(head);

    InsertionBeg(&head, 5);
    printf("After inserting at beginning: ");
    printList(head);

    InsertionMiddle(&head, 15);
    printf("After inserting at middle: ");
    printList(head);

    InsertionEnd(&head, 40);
    printf("After inserting at end: ");
    printList(head);

    return 0;
}