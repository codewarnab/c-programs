#include <stdio.h>

typedef struct Node {
    int val;
    struct Node *next;
    struct Node *child;
} Node; 

Node * createNode (int val ){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->child = NULL;

    return newNode; 
}

Node * flattenLinkedList(Node * head ){
    if(!head )
        return NULL;
    Node *current = head;
    Node *tail = head; 

    // Traverse to find the tail of the main list 
    while (tail->next )
    {
        tail = tail->next; 
    }
    

    while(current){
        // if theres a child , attach it to the tail 
        if(current->child){
            tail->next = current->child;

            Node *temp = current->child; 
            while ( temp ->next){
                temp = temp->next;
            }
            tail = temp; 
        }

        current->child = NULL; // clear the child pointer  
    }

    return head; 
}

void printList(Node * head ){
    while (head){
        printf("%d ->", head->val);
        head = head->next; 
    }
    printf("NULL \n ");
}

int main()
{
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->child = createNode(4);
    head->child->next = createNode(5);
    head->next->child = createNode(6);

    printf("Original list:\n");
    printList(head);

    head = flattenLinkedList(head);

    printf("Flattened list:\n");
    printList(head);

    return 0;
}
