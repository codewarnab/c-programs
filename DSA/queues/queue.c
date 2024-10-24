#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void show();

int items[100], front = -1, rear = -1, size;

int main()
{
    int choice;

    printf("Enter the maximum number of elements in the queue: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid size, exiting...\n");
        exit(0);
    }

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Please enter a valid choice\n");
        }
    }

    return 0;
}

void enqueue()
{
    int value;

    if (rear == size - 1) // Queue is full when rear equals size-1
    {
        printf("Queue is full!\n");
    }
    else
    {
        printf("Enter value to enqueue: ");
        scanf("%d", &value);

        if (front == -1) // When first element is added, initialize both front and rear
        {
            front = 0;
        }
        rear++; // Increment rear and add element
        items[rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

void dequeue()
{
    if (front == -1 || front > rear) // Queue is empty when front is -1 or front surpasses rear
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Dequeued: %d\n", items[front]);
        front++; // Increment front to remove the front element

        if (front > rear) // If the queue becomes empty, reset both front and rear
        {
            front = rear = -1;
        }
    }
}

void show()
{
    if (front == -1 || front > rear) // Queue is empty when front surpasses rear or it's -1
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Queue elements are: \n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", items[i]);
        }
        printf("\n");
    }
}
