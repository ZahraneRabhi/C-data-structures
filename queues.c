// Some ops over queueus n shit
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 20

int queueCount = 0 ;

typedef struct Queue {
  int e;
  struct Queue *next;
} Queue;


bool queueIsFull(){
  if (queueCount == MAX_QUEUE - 1){
    return true ;
  }
  return false ;
}


bool queueIsEmpty(Queue *head){
  if (head == NULL){
    return true ;
  }
}


void enqueue(Queue **head,int e){
  if (queueCount == MAX_QUEUE -1)
    return ;
  if (*head == NULL){
    *head = malloc(sizeof(Queue));
    (*head)->next = NULL ;
    (*head)->e = e ;
  } else {
        Queue *ptr = *head ;
        while(ptr->next != NULL){
          ptr = ptr->next ;
    }
    
    Queue *tmp = malloc(sizeof(Queue));
    tmp->next = NULL ;
    tmp->e = e ;
    ptr->next = tmp ;
  }
}


void dequeue(Queue **head,int *holder){
  if (*head != NULL){
    *holder = (*head)->e ;
    Queue *tmp = *head ;
    *head = tmp->next ;
    free(tmp);
    tmp = NULL;
  }
  else {
    return ;
  }
}


int main(){
  Queue *head = NULL ;
  int *holder = NULL ;
  /* Funcs can be used now */
  return 0 ;
}