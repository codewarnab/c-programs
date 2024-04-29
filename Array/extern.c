#include <stdio.h>

extern int arr[]; // Declaration with extern keyword

int main() {
    // Accessing the array elements
    printf("Array elements: %d, %d, %d\n", arr[0], arr[1], arr[2]);
    return 0;
}

int arr[] = {1, 2, 3}; // Definition of the array
