#include <stdio.h>
#include <stdlib.h>

// Definition of the doubly linked list node
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Node;

Node *head = NULL;

// Function to create a doubly linked list
void create()
{
    Node *newNode, *temp;
    int data;

    printf("Enter data (-1 to end): ");
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
            break;

        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

// Function to insert a node at the head of the list
void insertAtHead()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    printf("Enter data to insert at head: ");
    scanf("%d", &newNode->data);

    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

// Function to insert a node after a specific position
void insertAfter(int position)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    int i = 1;

    printf("Enter data to insert after position %d: ", position);
    scanf("%d", &newNode->data);

    while (i < position && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Position out of range.\n");
        free(newNode);
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

// Function to insert a node before a specific position
void insertBefore(int position)
{
    if (position == 1)
    {
        insertAtHead();
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = head;
    int i = 1;

    printf("Enter data to insert before position %d: ", position);
    scanf("%d", &newNode->data);

    while (i < position - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Position out of range.\n");
        free(newNode);
    }
    else
    {
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

// Function to insert a node at the end of the list
void insertAtEnd()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *temp = head;

    printf("Enter data to insert at end: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to display the doubly linked list
void display()
{
    Node *temp = head;

    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, pos;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create list\n");
        printf("2. Insert at head\n");
        printf("3. Insert after a position\n");
        printf("4. Insert before a position\n");
        printf("5. Insert at end\n");
        printf("6. Display list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insertAtHead();
            break;
        case 3:
            printf("Enter position to insert after: ");
            scanf("%d", &pos);
            insertAfter(pos);
            break;
        case 4:
            printf("Enter position to insert before: ");
            scanf("%d", &pos);
            insertBefore(pos);
            break;
        case 5:
            insertAtEnd();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
