#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// stack structue for characters

typedef struct
{
    int top;
    char items[MAX];
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1;
}

int push(Stack *s, char value)
{
    if (s->top == (MAX - 1))
    {
        printf("stack overflow \n");
        return;
    }
    s->items[++(s->top)] = value;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// FUnction to get the top element of the stack
char peek(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }

    return s->items[s->top];
}

// Fucntion to check id the characher is an operator

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of operators
int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void reverse(char *str)
{
    int start = 0;
    int end = strlen(str) - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void infixToPrefix(char *infix, char *prefix)
{
    Stack s;
    initStack(&s);
    int len = strlen(infix);
    char result[MAX];
    int j = 0;

    // reverse the infix expression
    reverse(infix);

    // Travsese trhough the reversed infix expression
    for (int i = 0; i < len; i++)
    {
        char current = infix[i];

        // if the current character is an operand , add it to the result
        if (isalnum(current))
        {
            result[j++] = current;
        }
        // if the current character is '(' push it to the stack
        else if (current == '(')
        {
            push(&s, current);
        }
        // if the current character is ')' pop and add to result until '(' is encountered
        else if (current == "(")
        {
            while (!isEmpty(&s) && peek(&s) != ')')
            {
                result[j++] = pop(&s);
            }
            pop(&s); // pop the '('

        }
        else if (isOperator(current))
        {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(current))
            {
                result[j++] = pop(&s);
            }
            push(&s, current);
        }

    }
    // Pop the remaining operators from the stack
    while (!isEmpty(&s))
    {
        result[j++] = pop(&s);
    }

    result[j] = '\0';

    // Reverse the result to get the prefix expression
    reverse(result);
    strcpy(prefix, result);
}   