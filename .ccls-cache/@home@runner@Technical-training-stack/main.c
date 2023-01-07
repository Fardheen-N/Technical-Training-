#include <stdio.h>
#include <stdlib.h>
struct stack{
    int * arr;
    int arrSize;
    int top;
};

struct stack * createStack(int size){
    struct stack * newStack = (struct stack *)malloc(sizeof(struct stack));
    newStack->arr = (int *)malloc(sizeof(int)*size);
    newStack->arrSize = size;
    newStack->top = -1;    
    return newStack;
}
int isFull(struct stack * s){
    return s->top == s->arrSize-1;
}

void push(struct stack * s,int data){
    if(isFull(s)){
        printf("Stack is full");
    } else {        
        s->arr[++(s->top)] = data;
    }
    return;
}
int isEmpty(struct stack * s){
    return s->top == -1;
}

void pop(struct stack * s){
    if(isEmpty(s)){
        printf("Stack is Empty");
    } else {
        s->arr[s->top] = -1;
        s->top--;
    }
    return;
}
int main(void) {
  struct stack * s1;
    int arrSize = 5;
    s1 = createStack(arrSize);
    push(s1,10);
    push(s1,20);
    push(s1,30);
    pop(s1);
    push(s1,30);
    push(s1,40);
    push(s1,50);
    push(s1,60);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    pop(s1);
  return 0;
}