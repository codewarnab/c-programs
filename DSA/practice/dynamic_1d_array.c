#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the size of the array :");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * (sizeof(int)));
    printf("Enter the values for the array \n");
    for (int i = 0; i < n; i++){
        printf("Enter value at index %d :", i);
        scanf("%d", &arr[i]);
    }
    printf("Here is the values from dynamic arrays ");
    for (int i = 0; i < n; i++){
        printf("%d  ", arr[i]);
    }
}