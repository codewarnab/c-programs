#include <stdio.h>
#include <stdlib.h>

// Definition of the circular linked list node
typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

// Function to create a circular linked list
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

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head; // Circular link
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Maintain circular link
        }
    }
}

// Function to count the number of nodes in the circular linked list
int count()
{
    if (head == NULL)
    {
        return 0;
    }

    Node *temp = head;
    int counter = 1;

    while (temp->next != head)
    {
        counter++;
        temp = temp->next;
    }

    return counter;
}

// Function to reverse the circular linked list
void reverse()
{
    if (head == NULL)
        return;

    Node *prev = NULL, *current = head, *next = NULL, *tail = head;

    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);

    // Adjust the head and tail pointers
    head->next = prev;
    head = prev;
}

// Function to display the circular linked list
void display()
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    Node *temp = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
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
            printf("The list has been reversed.\n");
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
