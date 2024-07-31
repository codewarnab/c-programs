#include <stdio.h>
#include <stdlib.h>

void insertElement(int **array, int *size, int pos, int value)
{
    // Reallocate memory to accommodate the new element
    *array = (int *)realloc(*array, (*size + 1) * sizeof(int));
    if (*array == NULL)
    {
        printf("Memory reallocation failed.\n");
        exit(1);
    }

    // Shift elements to the right from the specified position
    for (int i = *size; i > pos; i--)
    {
        (*array)[i] = (*array)[i - 1];
    }

    // Insert the new element
    (*array)[pos] = value;

    // Increment the size of the array
    (*size)++;
}

void deleteElement(int *array, int *size, int pos)
{
    // Shift elements to the left from the specified position
    for (int i = pos; i < *size - 1; i++)
    {
        array[i] = array[i + 1];
    }

    // Decrement the size of the array
    (*size)--;
}

void printArray(int *array, int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int n, choice, pos, value;

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

    // Loop for inserting and deleting elements
    while (1)
    {
        printf("\n1. Insert element\n2. Delete element\n3. Print array\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the position to insert the element (0 to %d): ", n);
            scanf("%d", &pos);
            if (pos < 0 || pos > n)
            {
                printf("Invalid position!\n");
                break;
            }
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertElement(&array, &n, pos, value);
            break;

        case 2:
            printf("Enter the position to delete the element (0 to %d): ", n - 1);
            scanf("%d", &pos);
            if (pos < 0 || pos >= n)
            {
                printf("Invalid position!\n");
                break;
            }
            deleteElement(array, &n, pos);
            break;

        case 3:
            printArray(array, n);
            break;

        case 4:
            // Free the allocated memory and exit
            free(array);
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
