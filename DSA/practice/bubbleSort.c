#include<stdio.h>

// function for bubble sort 
void bubbleSort(int arr[],int n ){
    int swapped = 0;
    for (int i = 0; i < n - 1;i++){
        for (int j = 0; j < n - 1 - i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
    if(swapped){
        break;
    }
    }

}