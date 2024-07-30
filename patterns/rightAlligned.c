//       *
//      **
//     ***
//    ****
//   *****
//  ******
// *******
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        // Print leading spaces
        for (int k = n; k > i; k--)
        {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        // Move to the next line
        printf("\n");
    }

    return 0;
}
