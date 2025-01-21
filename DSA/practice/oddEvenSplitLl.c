#include <stdio.h>
#include <stdlib.h>

// Define the structure of a linked list node

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new Node ;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void oddEvenSplit(Node *head, Node **oddList, Node **evenList)
{
    *oddList = NULL;
    *evenList = NULL;

    Node *oddTail = NULL;
    Node *evenTail = NULL;

    while (head)
    {
        if (head->data % 2 == 0)
        {
            if(*evenList == NULL){
                *evenList = head;
                evenTail = head; 
            }else {
                evenTail->next = head;  
                evenTail = head; 
            }
        }
        else
        {
            // Add to odd list
            if (*oddList == NULL)
            {
                *oddList = head;
                oddTail = head;
            }
            else
            {
                oddTail->next = head;
                oddTail = head;
            }
        }
        head = head->next;
    }

}