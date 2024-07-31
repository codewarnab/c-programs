#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols, i, j;

    // Prompt for the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the array OF THE POINTERS 
    int **arr = (int **)calloc(rows, sizeof(int *));

    //DYNAMICALLY allocate memory for the rows 
    for (i = 0; i < rows; i++)
    {
        arr[i] = (int *)calloc(cols, sizeof(int));
    }

    // Input elements into the array
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Print the elements of the array
    printf("Elements are:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
