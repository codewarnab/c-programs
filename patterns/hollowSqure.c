#include <stdio.h>

void printHollowSquare(int side)
{
    int i, j;

    for (i = 0; i < side; i++)
    {
        for (j = 0; j < side; j++)
        {
            // Print '*' for the border positions, otherwise print space
            if (i == 0 || i == side - 1 || j == 0 || j == side - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int side;

    printf("Enter the side length of the square: ");
    scanf("%d", &side);

    printHollowSquare(side);

    return 0;
}
