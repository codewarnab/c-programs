#include <stdio.h>

void selectionSort(int arr[], int n)
{
  int i, j, min_idx;

  for (i = 0; i < n - 1; i++)
  {
    min_idx = i;
    for (j = i + 1; j < n; j++)
    { 
      //this is for asscending order 
      if (arr[j] < arr[min_idx])
      {
        min_idx = j;
      }
    }
    // swap the found minimum element with the ith element
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

// Driver code to test above
int main()
{
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);
  selectionSort(arr, n);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}