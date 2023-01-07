#include <stdio.h>
#include <stdlib.h>
struct node{
 int data;
 struct node *next;
};
struct node *createNode(int data){
  struct node *newNode=(struct node*)malloc(sizeof(struct node));
  newNode->data=data;
  newNode->next=NULL;
  return newNode;
}
void insertAtBeginning(struct node **head,int data)
{
  struct node *newNode=createNode(data);
  if(*head==NULL){*head=newNode;}
  else{newNode->next=*head;*head=newNode;}
}
int main(void) {
  printf("Hello World\n");
  return 0;
}