#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the stack
struct Node
{
    int data;
    struct Node *next;
};

// Function to check if the stack is empty
int isEmpty(struct Node *top)
{
    return top == NULL;
}

// Function to push an element onto the stack
void push(struct Node **top, int value)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    // Set the new node's data and link it to the top of the stack
    newNode->data = value;
    newNode->next = *top;

    // Update the top pointer to the new node
    *top = newNode;

    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack is empty!\n");
        return -1; // Indicating stack underflow
    }

    // Remove the top node from the stack
    struct Node *temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;

    // Free the memory of the popped node
    free(temp);

    return poppedValue;
}

// Function to view the top element of the stack without removing it
int peek(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty!\n");
        return -1; // Indicating empty stack
    }
    return top->data;
}

// Function to display the elements of the stack
void display(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty!\n");
        return;
    }

    struct Node *current = top;
    printf("Stack elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Node *stack = NULL; // Initialize an empty stack

    // Test the stack operations
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    display(stack); // Output the current stack

    printf("Popped element: %d\n", pop(&stack)); // Pop an element
    display(stack);                              // Output the current stack

    printf("Peek top element: %d\n", peek(stack)); // Peek the top element

    return 0;
}
