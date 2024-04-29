#include <stdio.h>

int main() {
    // Method 1: int array[5] = {};
    int array1[5] = {};
    
    // Method 2: int array[5] = {0};
    int array2[5] = {0};

    // Method 3: 
    int a = 0,  b = 0,  c = 0;
    int array3[5] = {a, b, c};

    // Displaying the arrays
    printf("Array 1 (int array[5] = {}):\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");

    printf("Array 2 (int array[5] = {0}):\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");

    printf("Array 3 (int array[5] = {a, b, c}):\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array3[i]);
    }
    printf("\n");

    return 0;
}
