#include <stdio.h>
#include <stdlib.h>

#define NUM_ALPHA 26

int main()
{
    int n;
    printf("Enter number of characters you want to enter: ");
    scanf("%d", &n);
    getchar(); // Consume newline character left by scanf

    char *arr = (char *)malloc(sizeof(char) * n);
    int *hash = (int *)calloc(NUM_ALPHA, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        printf("Enter character at index %d: ", i);
        arr[i] = getchar(); // Read a single character
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            hash[arr[i] - 'a']++;
        }
        else
        {
            printf("Invalid character. Please enter a lowercase letter.\n");
            i--; // Retry current index
        }
        getchar(); // Consume newline character
    }

    printf("Enter number of elements you will search: ");
    int q;
    scanf("%d", &q);
    getchar(); // Consume newline character left by scanf

    printf("Enter %d characters to search: ", q);
    while (q--)
    {
        char s = getchar(); // Read a single character
        if (s >= 'a' && s <= 'z')
        {
            printf("Occurrence of %c is %d times\n", s, hash[s - 'a']);
        }
        else
        {
            printf("Invalid character. Please enter a lowercase letter.\n");
        }
        getchar(); // Consume newline character
    }

    free(arr);
    free(hash);

    return 0;
}
