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

void append(struct node ** headAddress,int data){
    struct node * newNode = createNode(data);
    struct node * temp = *headAddress;
    if(temp == NULL){
        *headAddress = newNode;
    } else {
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
}

void insertAtTheBegining(struct node ** headAddress,int data){
    struct node * newNode = createNode(data);
    if(*headAddress == NULL){
        *headAddress = newNode;
    } else {
        newNode->next = *headAddress;
        *headAddress = newNode;
    }
}
void insertAtSpecificPosition(struct node ** headAddress,int data, int pos){
    struct node * newNode = createNode(data);
    int tpos = 1;
    if(*headAddress == NULL && tpos == pos){
        *headAddress = newNode;
    } else if(tpos == pos){
        newNode->next = *headAddress;
        *headAddress = newNode;
    } else{
        struct node * temp = *headAddress;
        while(temp->next!= NULL && tpos != pos-1){
            temp = temp->next;
            tpos++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtLast(struct node ** headAddress){
    struct node * temp = *headAddress;
    if(*headAddress == NULL){
        return;
    } else if((*headAddress)->next == NULL){
        *headAddress = NULL;
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