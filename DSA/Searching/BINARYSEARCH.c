#include <stdio.h>

int a[100], n;

void bs() // Bubble sort
{
    int i, j, swap;
    printf("How many elements do you want to store? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element at index %d: ", i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap = a[j];
                a[j] = a[j + 1];
                a[j + 1] = swap;
                flag = 1;
            }
        }
        if (flag == 0) // Exit if no swaps occurred
            break;
    }
    printf("Sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n"); // Add a newline for better output formatting
}

// Binary Search in C
int binarySearch(int array[], int x, int low, int high)
{
    // Repeat until the pointers low and high meet each other
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    bs();
    do
    {
        printf("\nWhich element do you want to find? ");
        int x;
        scanf("%d", &x);
        int result = binarySearch(a, x, 0, n - 1);
        if (result == -1)
            printf("Not found\n");
        else
            printf("Element is found at index %d\n", result);
    } while (1); // Loop forever; you can break the loop based on user input if needed

    return 0; // Unreachable, but conventionally kept here
}
