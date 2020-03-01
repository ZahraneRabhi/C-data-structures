
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LinkedList {
    int e ;
    struct LinkedList *next ;
} LinkedList ;

int countNodes(LinkedList *head){
    if (head == NULL){
        return 0 ;
    }
    if (head->next == NULL){
        return 1 ;
    }
    else {
        int count = 0 ;
        LinkedList *ptr = head ;
        while(ptr != NULL){
            ptr = ptr->next ;
            count += 1 ;
        }
        return count ;
    }
}


void addHeadDoublePtr(LinkedList **head, int e) {
  if (*head == NULL) {
    *head = malloc(sizeof(LinkedList));
    (*head)->next = NULL;
    (*head)->e = e;
  }
  else {
    LinkedList *tmp = malloc(sizeof(LinkedList));
    tmp->next = *head;
    tmp->e = e;
    *head = tmp;
  }
}


LinkedList *addHeadSinglePtr(LinkedList *head,int e){
    if (head == NULL){
      head = malloc(sizeof(LinkedList));
      head->e = e ;
      head->next = NULL ;
      return head ;
    }
    else {
      LinkedList *tmp = malloc(sizeof(LinkedList));
      tmp->e = e ;
      tmp->next = head ;
      head = tmp ;
      return head ;
    }
}



bool addInMiddle(LinkedList *head ,int e , int pos){
  if ((pos<1) || (pos>countNodes(head))){
    return false ;
  }
  if (head == NULL){
    addHeadDoublePtr(&head,e);
    return true ;
  }
  else {
    LinkedList *ptr = head ;
    int count = 1 ;
    while (ptr->next != NULL){
      if (count == pos){
        break ;
      }
      ptr = ptr->next ;
      count++ ;
    }
    LinkedList *tmp = malloc(sizeof(LinkedList));
    tmp->next = ptr->next ;
    ptr->next = tmp ;
    return true ;
  }
}



void addTail(LinkedList *head, int e){
  if (head == NULL){
    addHeadDoublePtr(&head,e);
  }
  else {
    LinkedList *tmp = malloc(sizeof(LinkedList));
    tmp->next = NULL ;
    tmp->e = e ;
    LinkedList  *ptr = head ;
    while (ptr->next != NULL){
      ptr = ptr->next ;
    }
    ptr->next = tmp ;
  }
}

bool searchByElement(LinkedList *head, int x){
    LinkedList *ptr = head ;
    while (ptr != NULL)
    {
        if (ptr->e == x){
            return true ;
        }
        ptr = ptr->next ;
    }
    return false ;
}

int countElementOccurrs(LinkedList *head, int x){
    int occurrs = 0 ;
    LinkedList *ptr = head ;
    while (ptr != NULL)
    {
        if (ptr->e == x){
            occurrs += 1 ;
        }
        ptr = ptr->next ;
    }
    return occurrs;
}


int grabByIndex(LinkedList *head, int index ){
    if ((head == NULL) || (index < 0) || (index >= countNodes(head))){
        return -999;
    }
    LinkedList *ptr = head ;
    int count = 0 ;
    while (ptr->next != NULL)
    {
        if (count == index){
            return ptr->e ;
        }
        ptr = ptr->next ;
        count++ ;
    }
    return ptr->e ;
}


void popHeadDoublePtr(LinkedList **head){
    if ((*head) == NULL){
        return ;
    }
    else {
        LinkedList *neww = (*head)->next ;
        free(*head);
        *head = NULL ;
    }
}


LinkedList *popHeadSinglePtr(LinkedList *head){
    if (head == NULL){
        return NULL ;
    }
    else {
        LinkedList *new_head = head->next ;
        free(head) ;
        return new_head ;
    }
}


void popMid(LinkedList *head ,int pos){
    if ((pos >= countNodes(head))||(pos < 1) || (head == NULL)){
        return ;
    }
    else {
        LinkedList *ptr = head ;
        int count = 0 ;
        while(ptr->next->next != NULL){
            if (pos == count){
                break ;
            }
            ptr = ptr->next ;
            count += 1 ;
        }
        LinkedList *tmp = ptr->next ;
        ptr->next = ptr->next->next ;
        free(tmp);
        tmp = NULL ;
    }
}


void popValue(LinkedList *head , int x){
    if (head == NULL){
        return ;
    }
    if (head->next == NULL){
        if (head->e == x){
          popHeadDoublePtr(&head);
        }
    }
    else {
        LinkedList *ptr = head ;
        int count = 0 ;
        while (ptr->next != NULL)
        {
            if (ptr->e == x){
                popMid(ptr,count);
            }
            count += 1 ;
            ptr = ptr->next ;
        }
    }
}


void popTail(LinkedList *head){
    if ((head == NULL) || (head->next == NULL)){
            return ;
    }
    else {
        while(head->next->next != NULL){
            head = head->next ;
        }
        free(head->next);
        head->next = NULL ;
    }
}


void showAll(LinkedList *head){
  if (head != NULL){
    LinkedList *ptr = head ;
    while(ptr != NULL){
      printf("%d ",ptr->e);
      ptr = ptr->next ;
    }
    printf("\n"); 
  }
}



int main(){
    LinkedList *head = NULL;
    addHeadDoublePtr(&head,1);
    head = addHeadSinglePtr(head,40);
    showAll(head); 
    /* mf can start using the functions now */
    exit(0);
}
