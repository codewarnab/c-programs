#include <stdio.h>

// Merge two subarrays of arr[].
// first subarray is arr[low..mid] and second subarray is arr[mid+1..high]

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1; // size of the left subarray
    int n2 = high - mid;    // size of the right subarray

    // create temporary arrays
    int left[n1], right[n2];

    // copy data to temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i]; // Corrected indexing
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    // Merge the temporary arrays back into arr[low..high]
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // copying the remaining elements of the right[] if any
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

    // copy remaining elements of left[] if any
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++; // Corrected
    }
}


void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Find the mid index
        int mid = low + (high - low) / 2;

        // Recursively sort the two halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
