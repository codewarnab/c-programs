// Create a 1D array and delete an element from that array
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, pos;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read elements of the array
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    // Read the position of the element to delete
    printf("Enter the position to delete the element (0 to %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n)
    {
        printf("Invalid position!\n");
        free(array);
        return 1;
    }

    // Shift elements to the left from the specified position
    for (int i = pos; i < n - 1; i++)
    {
        array[i] = array[i + 1];
    }

    // Reduce the size of the array
    n--;

    // Print the updated array
    printf("Updated array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}
