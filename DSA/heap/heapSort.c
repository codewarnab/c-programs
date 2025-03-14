#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > largest)
    {
        largest = left;
    }
    if (right < n && arr[right] > largest)
    {
        largest = right;
    }

    if (largest != i)
    {
        // swap
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    // Build the max heap from the input
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // One by one extract elements from the heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move the current root ( largest to the end )
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call the heapify  on the reduces heap 
        heapify(arr, i, 0);
    }
}