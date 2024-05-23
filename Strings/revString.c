// Write a C Program to input a string and reverse its content.

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], reversed[100];
    int length, i, j;

    // Prompt user for input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove the newline character from the input string if present
    length = strlen(str);
    if (str[length - 1] == '\n')
    {
        str[length - 1] = '\0';
        length--;
    }

    // Reverse the string
    for (i = length - 1, j = 0; i >= 0; i--, j++)
    {
        reversed[j] = str[i];
    }
    reversed[j] = '\0'; // Null-terminate the reversed string

    // Output the reversed string
    printf("Reversed string: %s\n", reversed);

    return 0;
}
