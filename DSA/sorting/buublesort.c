// this is a bubble sort program for sorting in acsending order .
#include <stdio.h>

int main ()
 {   int flag ,arr[100],n,swap;
  printf(" Enter the number of elements you want to enter :");
 scanf("%d",&n);
 printf("Enter the array elemnets ");
 for (int i = 0; i < n; i++) {
     scanf("%d",&arr[i]);
 }
 for (int i = 0; i < n-1; i++)
  {
     flag = 0;
     for (int j = 0; j <n-i-1 ; j++)
      {
       if (arr[j]>arr[j+1]) 
       {
        swap = arr[j+1];
        arr[j+1]=arr[j];
        arr[j]= swap; 
        flag = 1;
       }
     } 
       if (flag==0)
       break;
 }
 printf("Etered array in sorted order ");
 for (int i = 0; i <n ; i++) {
     printf("%d  ",arr[i]);
 }
 
    return 0;
}