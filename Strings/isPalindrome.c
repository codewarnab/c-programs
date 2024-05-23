#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int isPalindrome(char str[])
{
    int low = 0;
    int high = strlen(str) - 1;

    while (low < high)
    {
        if (str[low] != str[high])
        {
            return 0; // not a palindrome.
        }
        low++;
        high--;
    }
    return 1; // is a palindrome
}

int main()
{
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Remove the newline character if present
    str[strcspn(str, "\n")] = '\0'; // strcspn returns the index of the first occurrence of '\n' in str or the length of str if '\n' is not found. 

    if (isPalindrome(str))
    {
        printf("%s is a palindrome\n", str);
    }
    else
    {
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}
