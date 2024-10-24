#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

// Function to create a linked list
void create()
{
    Node *temp, *newNode;
    int data;

    printf("Enter data (-1 to end): ");
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
            break;

        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
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
        }
    }
}

// Function to delete a node from the head of the list
void deleteAtHead()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from head.\n");
}

// Function to delete a node from the end of the list
void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    // If there is only one node
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    printf("Node deleted from end.\n");
}

// Function to delete a node by position
void deleteAtPosition()
{
    int pos, i = 1;

    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1)
    {
        deleteAtHead();
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && i < pos)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Invalid position!\n");
    }
    else
    {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", pos);
    }
}

// Function to delete a node by value
void deleteByValue()
{
    int value;

    printf("Enter the value of the node to delete: ");
    scanf("%d", &value);

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    Node *prev = NULL;

    // If the node to be deleted is the head
    if (head->data == value)
    {
        deleteAtHead();
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", value);
    }
    else
    {
        prev->next = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", value);
    }
}

// Function to display the linked list
void display()
{
    Node *temp = head;

    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create list\n");
        printf("2. Delete at head\n");
        printf("3. Delete at end\n");
        printf("4. Delete by position\n");
        printf("5. Delete by value\n");
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
            deleteAtHead();
            break;
        case 3:
            deleteAtEnd();
            break;
        case 4:
            deleteAtPosition();
            break;
        case 5:
            deleteByValue();
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
