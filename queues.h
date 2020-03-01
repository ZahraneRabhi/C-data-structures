// to be used for breadth-first search 
#ifndef QUEUES_IMPORT_H

#define QUEUES_IMPORT_H
#include<stdbool.h>
#include <stdlib.h>

typedef struct Tree {
  int e;
  struct Tree *left, *right;
} Tree;

typedef struct Queue {
  Tree *root;
  struct Queue *next;
} Queue;


bool isEmpty(Queue *head){
  if (head == NULL){
    return true ;
  }
  return false; 
}


void enqueue(Queue **head,Tree *root){
  if (*head == NULL){
    *head = malloc(sizeof(Queue));
    (*head)->next = NULL ;
    (*head)->root = root ;
    return ;
  }
  else {
    Queue *ptr = *head ;
    while(ptr->next != NULL){
      ptr = ptr->next ;
    }
    Queue *tmp = malloc(sizeof(Queue));
    tmp->next = NULL ;
    tmp->root = root ;
    ptr->next = tmp ;
  }
}


void dequeue(Queue **head, Tree **holder){
  if (*head != NULL){
    *holder = (*head)->root ;
    Queue *tmp = *head ;
    *head = tmp->next ;
    free(tmp) ;
  }
}

#endif