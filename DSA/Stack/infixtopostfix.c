#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = ch;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1; // Error condition
    }
    else
    {
        return stack[top--];
    }
}

char peek()
{
    if (top != -1)
    {
        return stack[top];
    }
    return -1;
}

// Function to determine precedence of operators
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char exp[], char ans[])
{
    int i = 0, j = 0; // i for exp (infix), j for ans (postfix)

    while (exp[i] != '\0')
    {
        // If the character is an operand, add it to the result
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z'))
        {
            ans[j++] = exp[i];
        }
        // If the character is '(', push it to the stack
        else if (exp[i] == '(')
        {
            push(exp[i]);
        }
        // If the character is ')', pop and append to ans until '(' is found
        else if (exp[i] == ')')
        {
            while (top != -1 && peek() != '(')
            {
                ans[j++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        // If the character is an operator
        else if (isOperator(exp[i]))
        {
            while (top != -1 && precedence(peek()) >= precedence(exp[i]))
            {
                ans[j++] = pop();
            }
            push(exp[i]);
        }
        i++;
    }

    // Pop all remaining operators from the stack
    while (top != -1)
    {
        ans[j++] = pop();
    }

    ans[j] = '\0'; // Null-terminate the result
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    gets(infix); // Warning: gets() is unsafe, use fgets() instead in real applications

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
