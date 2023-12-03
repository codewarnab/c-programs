#include <stdio.h>

int main (int argc, char *argv[])
 {  int arr[100],n,min,max;
     printf("Enter the number of elements  ");
   scanf("%d",&n);
   printf("Enter the array elemnets : ");
 for (int i = 0; i < n; i++)
  {
     scanf("%d",&arr[i]);
 }
 max = arr[0];min = arr[0];
 for (int i = 0; i < n; i++) {
     if (max<arr[i])
     {
         max=arr[i];
     }
     if (min>arr[i])
     {  min = arr[i];
     }
 }
 printf("max elemnet = %d min element = %d",max,min);
    return 0;
}