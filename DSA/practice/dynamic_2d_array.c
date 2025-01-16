#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c,r;
    printf("Enter the Number of columns ");
    scanf("%d", &c);
    printf("Enter the number of rows ");
    scanf("%d",&r);
    int **arr = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r;i++){
        arr[i] = (int *)malloc(c * sizeof(int));
    }

    printf("Enter the values of 2d array ");
    for (int i = 0; i < r; i++ ){
        for (int j = 0;  j <c; j++){
            printf("Enter value at [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Here is the 2D array:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0 ; 


}