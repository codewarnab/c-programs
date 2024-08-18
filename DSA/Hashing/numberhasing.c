#include <stdio.h>
#include <stdlib.h>

// Define the size of the hash table (adjust as needed)
#define HASH_SIZE 1000

int main()
{
    int n, q;

    // Input number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Initialize hash table with zeros
    int *hash = (int *)calloc(HASH_SIZE, sizeof(int));
    if (hash == NULL)
    {
        fprintf(stderr, "Memory allocation for hash table failed!\n");
        free(arr);
        return 1;
    }

    // Input elements into the array and precompute their frequencies
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);

        // Assuming all numbers are positive and less than HASH_SIZE
        if (arr[i] < HASH_SIZE && arr[i] >= 0)
        {
            hash[arr[i]] += 1;
        }
        else
        {
            printf("Number %d is out of hash table range!\n", arr[i]);
        }
    }

    // Input number of queries
    printf("Enter the number of queries: ");
    scanf("%d", &q);

    // Process each query
    printf("Enter %d query values:\n", q);
    while (q--)
    {
        int number;
        scanf("%d", &number);

        // Output the frequency of the number
        if (number < HASH_SIZE && number >= 0)
        {
            printf("%d\n", hash[number]);
        }
        else
        {
            printf("Number %d is out of hash table range!\n", number);
        }
    }

    // Free allocated memory
    free(arr);
    free(hash);

    return 0;
}
