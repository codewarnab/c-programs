#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data ;
    struct Node *next;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
};

void initializeQueue(struct Queue *q){
    q->front = NULL ;
    q->rear = NULL; 
}

int isEmpty(struct Queue *q ){
    return q->front == NULL ; 
}

void enqueue(struct Queue *q , int value ){

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed \n");
        return;
    }

    // set the data and next pointer od the new node
    newNode->data = value;
    newNode->next = NULL; 

    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode; 
    }else {
        // other wise , link the new node to the end of the queue and update the rear

        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Enqueued %d\n", value);
}

int dequeue(struct Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }

    struct Node *temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next; 

    // if the queue becomes empty set  rear to NULL 
    if(q->front == NULL){
        q->rear = NULL; 
    }

    free(temp);

    return dequeuedValue;
}

void display(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }

    struct Node *current = q->front;
    printf("Queue elements: ");
    while (current!=NULL)
    {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
   
}