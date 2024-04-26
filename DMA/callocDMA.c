//CALLOC = contigious allocation 
#include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
 #include<string.h>
 int main ()
 {

     int n,i,*ptr ;
     printf("Total Number Of Values:: ");
     scanf("%d",&n);
     ptr =(int*)calloc(n,sizeof(int));
     printf("Enter values ");
     for (i = 0; i < n; i++) {
     scanf("%d",(ptr+i));
     }    
     printf("the Entred values are\n ");
     for ( i = 0; i <n ; i++) {
          printf("%d\t",*(ptr+i));
          }
 free (ptr);
 return 0;
}










 