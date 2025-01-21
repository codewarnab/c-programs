#include <stdio.h>

void bubbleSortPass(int arr[], int n)
{
    // Base case : if the array size is 1 , no need to sort further
    if (n == 1)
    {
        return;
    }

    // perform one pass of bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            // swap the lements if they are in the wrong order
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }

        // Recusively call bubbleSortPass for the next smaller array
        bubbleSortPass(arr, n - 1);
    }
}