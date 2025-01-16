#include <stdio.h>
#include <stdlib.h>

int main(){
    int c,r,nonZeroCount=0 ; 
    printf("Enter the  number of rows: ");
    scanf("%d",&r);
    printf("Enter the  number of columns: ");
    scanf("%d",&c);

    int matrix[r][c]; 
    printf("Enter the element of the matrix (0 for emepty :)\n");
    for(int i=0 ; i < r ; i++){
        for (int j = 0 ; j < c ; j++){
            printf("Element at [%d][%d]", i, j);
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
            {
                nonZeroCount++;
            }
        }
    }

    int *rowIndices = (int *)malloc(nonZeroCount * sizeof(int));
    int *colIndices = (int *)malloc(nonZeroCount * sizeof(int));
    int *values = (int *)malloc(nonZeroCount * sizeof(int)); 

    int k = 0 ; 
    for (int i = 0 ; i < r ; i ++){
        for (int j = 0 ; j< c; j++){
            if(matrix[i][j]!=0){
                rowIndices[k]= i ;
                colIndices[k] = j;
                values[k] = matrix[i][j];
                k++; 
            }
        }
    }
    printf("\nShortcut form (Compact form) of the sparse matrix:\n");
    printf("Row Index | Column Index | Value\n");
    for (int i = 0; i < nonZeroCount; i++)
    {
        printf("%d\t\t%d\t\t%d\n", rowIndices[i], colIndices[i], values[i]);
    }

    // Free the allocated memory
    free(rowIndices);
    free(colIndices);
    free(values);

    return 0;
}