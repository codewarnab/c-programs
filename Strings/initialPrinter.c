// Write a C Program to input a full name and display the initials.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void printInitials(char name[])
{
    int len = strlen(name);

    // Print the first character of the first word as uppercase initial
    if (len > 0)
    {
        printf("%c", toupper(name[0]));
    }

    // Traverse the string to find spaces and print the next character after a space as uppercase initial
    for (int i = 1; i < len; i++)
    {
        if (name[i] == ' ' && name[i + 1] != ' ' && name[i + 1] != '\0')
        {
            printf(" %c", toupper(name[i + 1])); // Add a space before printing the initial
        }
    }
    printf("\n");
}

int main()
{
    char name[MAX_LENGTH];

    printf("Enter a full name: ");
    fgets(name, MAX_LENGTH, stdin);

    // Remove the newline character if present
    name[strcspn(name, "\n")] = '\0';

    printf("Initials: ");
    printInitials(name);

    return 0;
}
