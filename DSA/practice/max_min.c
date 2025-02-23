#include<stdio.h>

typedef struct {
    int min; 
    int max ;
} Pair; 


// Function to find the minimum and maximum in the subarray arr[low...high]

Pair getMinMax(int arr[],int low, int high ){
    Pair result , leftPair  , rightPair ; 

    // Base Case 1 : Only one element 
    if(low == high){
        result.max = arr[low];
        result.max = arr[low];

        return result; 
    }
    // Base case 2 : Two elements
    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // Divide : Find the midpoint
    int mid = (low + high) / 2; 

    // Conquer : Recursivley find the min and max in the left and right subarrays
    leftPair = getMinMax(arr, low, mid);
    rightPair = getMinMax(arr, mid + 1, high);

    // combine : the overall minimum is the smalller of the two mins , 
    // and the overall maximum is the larger  of the two maxes .
    result.min = (leftPair.min < rightPair.min) ? leftPair.min : rightPair.min;
    result.max = (leftPair.max > rightPair.max) ? leftPair.max : rightPair.max; 
}

int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the function on the full array.
    Pair minmax = getMinMax(arr, 0, n - 1);

    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);

    return 0;
}
