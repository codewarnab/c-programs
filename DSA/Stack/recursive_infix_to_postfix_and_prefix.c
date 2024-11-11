#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Helper function to determine precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to check if character is an operator
int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to evaluate the postfix form recursively
void infixToPostfix(char *infix, int start, int end, char *postfix, int *pIndex)
{
    // Base case: single operand
    if (start == end)
    {
        postfix[(*pIndex)++] = infix[start];
        return;
    }

    // Track lowest precedence operator outside parentheses
    int minPrecedence = 4;
    int minIndex = -1;
    int openParens = 0;

    for (int i = start; i <= end; i++)
    {
        if (infix[i] == '(')
            openParens++;
        else if (infix[i] == ')')
            openParens--;
        else if (isOperator(infix[i]) && openParens == 0 && precedence(infix[i]) <= minPrecedence)
        {
            minPrecedence = precedence(infix[i]);
            minIndex = i;
        }
    }

    // Recursively process left and right parts
    infixToPostfix(infix, start, minIndex - 1, postfix, pIndex);
    infixToPostfix(infix, minIndex + 1, end, postfix, pIndex);

    // Append the operator
    postfix[(*pIndex)++] = infix[minIndex];
}

// Function to evaluate the prefix form recursively
void infixToPrefix(char *infix, int start, int end, char *prefix, int *pIndex)
{
    // Base case: single operand
    if (start == end)
    {
        prefix[(*pIndex)++] = infix[start];
        return;
    }

    // Track lowest precedence operator outside parentheses
    int minPrecedence = 4;
    int minIndex = -1;
    int openParens = 0;

    for (int i = start; i <= end; i++)
    {
        if (infix[i] == '(')
            openParens++;
        else if (infix[i] == ')')
            openParens--;
        else if (isOperator(infix[i]) && openParens == 0 && precedence(infix[i]) <= minPrecedence)
        {
            minPrecedence = precedence(infix[i]);
            minIndex = i;
        }
    }

    // Append the operator first for prefix
    prefix[(*pIndex)++] = infix[minIndex];

    // Recursively process left and right parts
    infixToPrefix(infix, start, minIndex - 1, prefix, pIndex);
    infixToPrefix(infix, minIndex + 1, end, prefix, pIndex);
}

int main()
{
    char infix[100], postfix[100], prefix[100];
    int postfixIndex = 0, prefixIndex = 0;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    int length = strlen(infix);

    // Convert infix to postfix
    infixToPostfix(infix, 0, length - 1, postfix, &postfixIndex);
    postfix[postfixIndex] = '\0'; // Null-terminate the postfix string
    printf("Postfix expression: %s\n", postfix);

    // Convert infix to prefix
    infixToPrefix(infix, 0, length - 1, prefix, &prefixIndex);
    prefix[prefixIndex] = '\0'; // Null-terminate the prefix string
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
