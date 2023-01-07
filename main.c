#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
};

struct node * createNode(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct node ** head,int data){
    struct node * newNode = createNode(data);
    struct node * temp = *head;
    if(temp == NULL){
        *head = newNode;
    } else {
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
}

void insertAtTheBegining(struct node ** head,int data){
    struct node * newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}
void insertAtSpecificPosition(struct node ** head,int data, int pos){
    struct node * newNode = createNode(data);
    int tpos = 1;
    if(*head == NULL && tpos == pos){
        *head = newNode;
    } else if(tpos == pos){
        newNode->next = *head;
        *head = newNode;
    } else{
        struct node * temp = *head;
        while(temp->next!= NULL && tpos != pos-1){
            temp = temp->next;
            tpos++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtLast(struct node ** head){
    struct node * temp = *head;
    if(*head == NULL){
        return;
    } else if((*head)->next == NULL){
        *head = NULL;
        free(temp);
    } else {
        struct node * prev = NULL;        
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}
void printList(struct node *head)
{
  while(head!=NULL)
    {
      printf("%d\n",head->data);
      head=head->next;
    }
}
int main(void) {
  struct node * head = NULL;
    insertAtTheBegining(&head,10);
    insertAtTheBegining(&head,20);
    insertAtTheBegining(&head,30);
    insertAtTheBegining(&head,40);
    insertAtTheBegining(&head,50);
    deleteAtLast(&head);
    deleteAtLast(&head);
    deleteAtLast(&head);
    //deleteAtLast(&head);
    //deleteAtLast(&head);
    printList(head);
  return 0;
}