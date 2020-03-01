// Counting stacks 💰 & performing some ops.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 20

typedef struct Stack {
  int e;
  struct Stack *next;
} Stack;

int stackCount = 0 ;

bool isFull(Stack *head){
  if (stackCount == MAX_STACK - 1){
    return true ;
  }
  return false;
}


bool isEmpty(Stack *head){
  if (head == NULL){
    return true;
  }
  return false ;
}


void push(Stack **head,int e){ 
  // double pointers so a mf won't  keep bouncing head ptr
  if (isFull(*head)){
    return ;
  }
  if (*head == NULL){
      *head = malloc(sizeof(Stack));
      (*head)->next = NULL ;
      (*head)->e =e ;
      stackCount += 1 ;
    } else {
        Stack *tmp = malloc(sizeof(Stack));
        tmp->e = e ;
        tmp->next = *head ;
        *head = tmp ;
        stackCount += 1 ;
    }
}



void pop(Stack **head, int *hold){
  if (isEmpty(*head)){
    return ;
  }
  else {
    *hold = (*head)->e ;
    Stack *tmp = *head ;
    *head = (*head)->next;
    free(tmp);
    tmp = NULL ;
    stackCount -= 1 ;
  }
}

void printStack(Stack *head) {
  printf("Moneybag has: ");
  while (head != NULL) {
    printf("%d ", head->e);
    head = head->next;
  }
  printf("\n");
}

int main(){
  int *hold = NULL ;
  Stack *head = NULL ;
  push(&head, 2);
  push(&head,69); 
  printStack(head);
  return 0 ;
}