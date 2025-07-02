#include <stdio.h>

void Merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    /**
     * Computes the size of the left subarray in merge sort.
     *
     * The left subarray spans from index `left` to `mid`, inclusive.
     * Hence we add 1 to account for both endpoints:
     *     number_of_elements = mid - left + 1
     */
    int n1 = mid - left + 1;
    int n2 = right - mid ;

    int L[n1], R[n2];

    // copy data to temp arrays
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergesort(int arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // sort first and second halves
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        Merge(arr, left, mid, right);
    }
}

void display(int arr[], int size)
{
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: \n ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergesort(arr, 0, n - 1);
    display(arr, n);

    return 0;
}