#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, pos, value;

    // Read the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *array = (int *)malloc((n + 1) * sizeof(int));
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

    // Read the position and the value to insert
    printf("Enter the position to insert the element (0 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n)
    {
        printf("Invalid position!\n");
        free(array);
        return 1;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    // Shift elements to the right from the specified position
    for (int i = n; i > pos; i--)
    {
        array[i] = array[i - 1];
    }
    

    // Insert the new element
    array[pos] = value;

    // Print the updated array
    printf("Updated array: ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}
