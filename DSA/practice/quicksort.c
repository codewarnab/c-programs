#include <stdio.h>

void swap(int * a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp; 
}

// partition function to place the pivot element at its correct position 
int partition(int arr[],int low, int high){
    int pivot = arr[high]; // pivot element
    int i = low - 1; // index for smaller element

    for (int j = low; j < high; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]); // place pivot in correct position

    return i + 1;
}


void quickSort(int arr[],int low , int high){
    if(low < high){
        int pi = partition(arr, low, high); // partion index 

        /// recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[],int n ){
    for (int i = 0; i < n; i++){
        printf("%d", arr[i]);

    }
    printf("\n");
}

int main(){
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0; 
}