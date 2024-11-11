#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
struct Stack
{
    int top;
    char arr[MAX];
};

// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->top == MAX - 1;
}

// Push an element onto the stack
void push(struct Stack *stack, char c)
{
    if (!isFull(stack))
    {
        stack->arr[++stack->top] = c;
    }
}

// Pop an element from the stack
char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->arr[stack->top--];
    }
    return '\0';
}

// Peek at the top element of the stack
char peek(struct Stack *stack)
{
    return stack->arr[stack->top];
}

// Function to return precedence of operators
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

// Check if the character is an operator
int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Infix to Postfix conversion
void infixToPostfix(char *infix, char *postfix)
{
    struct Stack stack;
    initialize(&stack);
    int i, j = 0;

    for (i = 0; infix[i]; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(&stack, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(&stack) && peek(&stack) != '(')
            {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop the '('
        }
        else if (isOperator(infix[i]))
        {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(infix[i]))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }

    // Pop all remaining operators
    while (!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

// Function to reverse a string
void reverse(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Infix to Prefix conversion
void infixToPrefix(char *infix, char *prefix)
{
    // Reverse the infix expression
    reverse(infix);
    struct Stack stack;
    initialize(&stack);

    // Replace '(' with ')' and vice versa
    for (int i = 0; infix[i]; i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    // Convert the reversed infix expression to postfix
    infixToPostfix(infix, prefix);

    // Reverse the postfix expression to get the prefix
    reverse(prefix);
}

int main()
{
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
