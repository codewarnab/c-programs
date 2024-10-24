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

// Function to count the number of nodes in the list
int count()
{
    int cnt = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

// Function to reverse the linked list
void reverse()
{
    Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move the prev and current one step forward
        current = next;
    }
    head = prev; // Update the head to the new first node
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
        printf("2. Count nodes\n");
        printf("3. Reverse list\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            printf("Total nodes: %d\n", count());
            break;
        case 3:
            reverse();
            printf("List has been reversed.\n");
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
