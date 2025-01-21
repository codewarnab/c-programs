#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data ;
    struct Node *next; 
};

int isEmpty(struct Node *top){
    return top == NULL;
}

void push(struct Node** top , int value ){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); 

    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = top; 

    *top = newNode;
    printf("Pushed %d onto the stack \n", value); 

}

int pop(struct Node** top ){
    if(isEmpty(top)){
        printf("Stack is empty\n");
        return -1;
    }
    struct Node  *temp = *top; 
    int poppedValue = temp->data;
    *top = (*top)->next;

    free(temp);
    return poppedValue;
}