//       *      
//      ***     
//     *****    
//    *******   
//   *********  
//  *********** 
// *************
#include <stdio.h>

void printPyramid(int height)
{
    int i, j, k;

    for (i = 1; i <= height; i++)
    {
        // Print leading spaces
        for (j = i; j < height; j++)
        {
            printf(" ");
        }
        // Print stars
        for (k = 1; k <= (2 * i - 1); k++)
        {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }
}

int main()
{
    int height;

    printf("Enter the height of the pyramid: ");
    scanf("%d", &height);

    printPyramid(height);

    return 0;
}
