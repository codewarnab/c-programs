#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);


    int **arr = (int **)malloc(rows * sizeof(int *));
    int *cols = (int *)malloc(rows * sizeof(int));

    // Allocate memory for each row with a different number of columns
    for (i = 0; i < rows; i++)
    {
        printf("Enter the number of columns for row %d: ", i);
        scanf("%d", &cols[i]);
        arr[i] = (int *)malloc(cols[i] * sizeof(int));

        // Input elements into the current row
        for (j = 0; j < cols[i]; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Elements are:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols[i]; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    free(cols);

    return 0;
}
