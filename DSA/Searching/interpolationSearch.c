#include <stdio.h> 

int interpolationSearchIterative(int arr[],int n , int key ){
    int low = 0, high = n - 1; 

    while(low <= high && key >= arr[low] && key <= arr[high]){
        // calculate the postion  using the interpolation formula
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]); 

        // check if the key is found 
        if (arr[pos] == key ){
            return pos; 
        }

        // if the key is larger , searh the upper part 
        if(arr[pos]<key){
            low = pos + 1;
        }
        else {
            high = pos - 1; 
        }
    }

    return -1; // key not found
}


int interpolationSearchRecursive(int arr[],int low , int high , int key ){
    if (low <= high && key >= arr[low] && key <= arr[high]){
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if(arr[pos] == key ){
            return pos;
        }

        // if the key is larger , searh the upper part 
        if(arr[pos] < key){
            return interpolationSearchRecursive(arr, pos + 1, high, key);
        }
        
        // if the key is smaller , searh the lower part
        return interpolationSearchRecursive(arr, low, pos - 1, key);
    }

    return -1 ; // key not found 
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 40;

    // Iterative search
    int resultIterative = interpolationSearchIterative(arr, n, key);
    if (resultIterative != -1)
        printf("Iterative: Element %d found at index %d.\n", key, resultIterative);
    else
        printf("Iterative: Element %d not found.\n", key);

    // Recursive search
    int resultRecursive = interpolationSearchRecursive(arr, 0, n - 1, key);
    if (resultRecursive != -1)
        printf("Recursive: Element %d found at index %d.\n", key, resultRecursive);
    else
        printf("Recursive: Element %d not found.\n", key);

    return 0;
}
