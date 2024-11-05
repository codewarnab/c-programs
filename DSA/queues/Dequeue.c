#include <stdio.h>
#include <stdlib.h>

#define N 5
int deque[N];
int front = -1, rear = -1;

// Function prototypes
void enqueueFront(int x);
void enqueueRear(int x);
void display();
void getFront();
void getRear();
void dequeueFront();
void dequeueRear();

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nCircular Deque Operations:\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display\n");
        printf("6. Get Front\n");
        printf("7. Get Rear\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue at front: ");
            scanf("%d", &value);
            enqueueFront(value);
            break;
        case 2:
            printf("Enter value to enqueue at rear: ");
            scanf("%d", &value);
            enqueueRear(value);
            break;
        case 3:
            printf("Dequeue from front: ");
            dequeueFront();
            break;
        case 4:
            printf("Dequeue from rear: ");
            dequeueRear();
            break;
        case 5:
            printf("Deque contents: ");
            display();
            break;
        case 6:
            printf("Front element: ");
            getFront();
            break;
        case 7:
            printf("Rear element: ");
            getRear();
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void enqueueFront(int x)
{
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }
    else if (front == 0)
    {
        front = N - 1;
        deque[front] = x;
    }
    else
    {
        front--;
        deque[front] = x;
    }
}

void enqueueRear(int x)
{
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }
    else if (rear == -1)
    {
        rear = 0;
        deque[rear] = x;
    }
    else
    {
        rear++;
        deque[rear] = x;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    printf("Deque elements: ");
    while (i != rear)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % N;
    }
    printf("%d ", deque[rear]); // Print the rear element
    printf("\n");
}

void getFront()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d\n", deque[front]);
    }
}

void getRear()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d\n", deque[rear]);
    }
}

void dequeueFront()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("Dequeued element: %d\n", deque[front]);
        front = rear = -1;
    }
    else if (front == N - 1)
    {
        printf("Dequeued element: %d\n", deque[front]);
        front = 0;
    }
    else
    {
        printf("Dequeued element: %d\n", deque[front]);
        front++;
    }
}

void dequeueRear()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("Dequeued element: %d\n", deque[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("Dequeued element: %d\n", deque[rear]);
        rear = N - 1;
    }
    else
    {
        printf("Dequeued element: %d\n", deque[rear]);
        rear--;
    }
}
