#include<stdio.h>
#include<stdlib.h>

struct node {
    int data ;
    struct node *next;
};

struct node *front = 0 ; 
struct node * rear = 0 ; 

void enqueue( int x ){
    struct node *newNode ;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = 0; 

    if(rear==0){
        front = rear = newNode;
        rear->next = front; 
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; 
    }

}