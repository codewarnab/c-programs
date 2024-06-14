#include <stdio.h>
int main()
{
    unsigned int rows = 0;
    printf("Enter the number of rows = ");
    scanf("%u",&rows);
    for (int i = 1; i <=rows  ; i++) {
        for (int j = 1; j <= i  ; j++)
         {
            if ( (i==j)|| (j==1)|| (i==rows))
            printf("*");
            else
            printf(" ");
        } 
        printf("\n");
    }
    return 0;
}