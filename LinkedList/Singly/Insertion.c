#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

//Creation of node
struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (!newNode){
    printf("Memory error\n");
    exit(1);
  }

  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
//Insertion of node at beginning
void insertionBeg(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

//insertion of node at end
void insertionEnd(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  if(*head == NULL) {
    *head = newNode;
    return;
  }
  
  struct Node* temp = *head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
}

//insertion of node in the middle
void insertionMiddle(struct Node** head, int data){
  if(*head == NULL){
    struct Node* newNode = createNode(data);
    return;
  }
  struct Node* slow = *head;
  struct Node* fast = *head;
  while(fast->next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  struct Node* newNode = createNode(data);
  newNode->next = slow->next;;
  slow->next = newNode;
}

//Traversal of node : 
void traversal(struct Node* head) {
  while( head != NULL ){
    printf("%d -> ", head->data);
    head = head->next;
  };
  printf("NULL\n");
}

int main(){
  struct Node* head = NULL;

  insertionEnd(&head,10);
  insertionEnd(&head,20);
  insertionEnd(&head,30);
  printf("Elements are : \n");
  traversal(head);

  insertionBeg(&head,5);
  printf("Elements are : \n");
  traversal(head);

  insertionMiddle(&head,25);
  printf("Elements are : \n");
  traversal(head);
  return 0;
}