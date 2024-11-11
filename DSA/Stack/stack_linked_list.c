#include <stdio.h>
#include <stdlib.h>

// Define the structure for each node in the stack
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node *top)
{
    return top == NULL;
}

// Push an element onto the stack
void push(struct Node **top, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *top; // Point new node to the current top
    *top = newNode;       // Update top to new node
    printf("%d pushed to stack\n", data);
}

// Pop an element from the stack
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        struct Node *temp = *top;
        int poppedData = temp->data;
        *top = (*top)->next;
        free(temp);
        return poppedData;
    }
}

// Peek at the top element of the stack
int peek(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return top->data;
    }
}

int main()
{
    struct Node *stack = NULL; // Initialize an empty stack

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(stack));

    printf("%d popped from stack\n", pop(&stack));
    printf("Top element after pop is %d\n", peek(stack));

    return 0;
}
