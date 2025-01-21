#include <stdio.h>

// Recursive function for linear search
int linearSearch(int arr[], int n, int key, int index)
{
    // Base case: If index reaches the size of the array, key not found
    if (index == n)
    {
        return -1; // Key not found
    }

    // Check if the current element matches the key
    if (arr[index] == key)
    {
        return index; // Return the index of the found key
    }

    // Recursive call to search in the remaining array
    return linearSearch(arr, n, key, index + 1);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int result = linearSearch(arr, n, key, 0); // Start search from index 0

    if (result != -1)
    {
        printf("Key %d found at index %d.\n", key, result);
    }
    else
    {
        printf("Key %d not found in the array.\n", key);
    }

    return 0;
}
