#include<stdio.h>

void insertionSort(int arr[],int n ){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = j - 1; 

        // Move elements of arr[0...i-1] that are greather than the key 
        // shift on position right  
        while (j > 0 && arr[j]>key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // insert the key in its correct position 
    }
}