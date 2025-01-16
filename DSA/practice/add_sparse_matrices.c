#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c1, c2, r1, r2, nz1 = 0, nz2 = 0;

    // first matrix
    printf("Enter the number of rows in first matrix: ");
    scanf("%d", &r1);
    printf("Enter the number of columns in the first matrix: ");
    scanf("%d", &c1);

    printf("Enter the number of rows in second matrix: ");
    scanf("%d", &r2);
    printf("Enter the number of columns in the second matrix: ");
    scanf("%d", &c2);

    // Check if matrix dimensions are same for addition
    if (r1 != r2 || c1 != c2)
    {
        printf("Matrix dimensions do not match for addition.\n");
        return 1;
    }

    printf("\nEnter values for the first matrix\n");
    int matrix1[r1][c1];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("Enter value at [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
            if (matrix1[i][j] != 0)
            {
                nz1++;
            }
        }
    }

    printf("\nEnter values for the second matrix\n");
    int matrix2[r2][c2];
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("Enter value at [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
            if (matrix2[i][j] != 0)
            {
                nz2++;
            }
        }
    }

    // Allocating memory for row indices, column indices, and values for both matrices
    int *columnIndices1 = (int *)malloc(nz1 * sizeof(int));
    int *rowIndices1 = (int *)malloc(nz1 * sizeof(int));
    int *values1 = (int *)malloc(nz1 * sizeof(int));

    int *columnIndices2 = (int *)malloc(nz2 * sizeof(int));
    int *rowIndices2 = (int *)malloc(nz2 * sizeof(int));
    int *values2 = (int *)malloc(nz2 * sizeof(int));

    // Build the first sparse matrix
    int k1 = 0;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            if (matrix1[i][j] != 0)
            {
                rowIndices1[k1] = i;
                columnIndices1[k1] = j;
                values1[k1] = matrix1[i][j];
                k1++;
            }
        }
    }

    // Build the second sparse matrix
    int k2 = 0;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            if (matrix2[i][j] != 0)
            {
                rowIndices2[k2] = i;
                columnIndices2[k2] = j;
                values2[k2] = matrix2[i][j];
                k2++;
            }
        }
    }

    // Initialize variables for the result of the addition
    int *resultRowIndices = (int *)malloc((nz1 + nz2) * sizeof(int));
    int *resultColumnIndices = (int *)malloc((nz1 + nz2) * sizeof(int));
    int *resultValues = (int *)malloc((nz1 + nz2) * sizeof(int));
    int k3 = 0;

    // Perform matrix addition
    int i = 0, j = 0;
    while (i < nz1 && j < nz2)
    {
        if (rowIndices1[i] < rowIndices2[j] || (rowIndices1[i] == rowIndices2[j] && columnIndices1[i] < columnIndices2[j]))
        {
            // Copy element from the first matrix
            resultRowIndices[k3] = rowIndices1[i];
            resultColumnIndices[k3] = columnIndices1[i];
            resultValues[k3] = values1[i];
            i++;
        }
        else if (rowIndices1[i] > rowIndices2[j] || (rowIndices1[i] == rowIndices2[j] && columnIndices1[i] > columnIndices2[j]))
        {
            // Copy element from the second matrix
            resultRowIndices[k3] = rowIndices2[j];
            resultColumnIndices[k3] = columnIndices2[j];
            resultValues[k3] = values2[j];
            j++;
        }
        else
        {
            // Both matrices have a non-zero element at the same position
            resultRowIndices[k3] = rowIndices1[i];
            resultColumnIndices[k3] = columnIndices1[i];
            resultValues[k3] = values1[i] + values2[j];
            i++;
            j++;
        }
        k3++;
    }

    // Copy remaining elements from matrix 1
    while (i < nz1)
    {
        resultRowIndices[k3] = rowIndices1[i];
        resultColumnIndices[k3] = columnIndices1[i];
        resultValues[k3] = values1[i];
        i++;
        k3++;
    }

    // Copy remaining elements from matrix 2
    while (j < nz2)
    {
        resultRowIndices[k3] = rowIndices2[j];
        resultColumnIndices[k3] = columnIndices2[j];
        resultValues[k3] = values2[j];
        j++;
        k3++;
    }

    // Print the result
    printf("\nShortcut form (Compact form) of the resulting sparse matrix:\n");
    printf("Row Index | Column Index | Value\n");
    for (int i = 0; i < k3; i++)
    {
        printf("%d\t\t%d\t\t%d\n", resultRowIndices[i], resultColumnIndices[i], resultValues[i]);
    }

    // Free allocated memory
    free(rowIndices1);
    free(columnIndices1);
    free(values1);
    free(rowIndices2);
    free(columnIndices2);
    free(values2);
    free(resultRowIndices);
    free(resultColumnIndices);
    free(resultValues);

    return 0;
}
