// Level order traversal 

// start at the root node . 
// use a queue to keep track of nodes at each level 
// for each node , print its data , then enqueue its left and right children ( if they exists ). 
// continue until the queue is empty 

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node 

struct node* createNode(int data ){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

struct QueueNode{
    struct node *treeNode;
    struct QueueNode *next;
}; 

// queue structure to hold tree for level-order traversal 

struct Queue{
    struct QueueNode *front, *rear;
};

struct Queue * createQueue(){
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue)); 
    
}
