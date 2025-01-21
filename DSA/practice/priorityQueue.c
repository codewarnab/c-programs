#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;          // Data value
    int priority;      // Priority of the element
    struct Node *next; // Pointer to the next node
} Node;

// Function to create a new node
Node *createNode(int data, int priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    return newNode;
}

// Fucntion to inser an element into the priority queue

void enqueue(Node **head, int data, int priority)
{
    Node *newNode = createNode(data, priority);

    // if the queue is empty or the new node  has the highest prority
    // here 1 means higher priority than 2 
    if (*head == NULL || (*head)->priority > priority)
    {
        newNode->next = *head;
        *head = newNode; // newNode becomes the head of the queue 
    }
    else
    {
        Node *temp = *head;
        // Traverse the list to find rhe correct position
        while (temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void dequeue(Node **head)
{
    if (*head == NULL)
    {
        printf("Priority Queue is empty!\n ");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("Priority Queue:\n ");
    while (head != NULL)
    {
        printf("Data: %d, Priority: %d \n ", head->data, head->priority);
        head = head->next;
    }
}

int main(){

    Node *priorityQueue = NULL;

    // Example operations
    enqueue(&priorityQueue, 10, 2);
    enqueue(&priorityQueue, 20, 1);
    enqueue(&priorityQueue, 30, 3);

    display(priorityQueue);

    printf("\nDequeuing highest priority element...\n");
    dequeue(&priorityQueue);
    display(priorityQueue);

    return 0;
}