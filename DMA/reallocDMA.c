//REALLOC= reallocation of memory 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main ()
{
      int n,n1,n2,i,*ptr ;
     printf("Total Number Of Values ");
     scanf("%d",&n);
     ptr =(int*)calloc(n,sizeof(int));
     printf("Enter values ");
for (i = 0; i < n; i++) 
  {   
       scanf("%d",(ptr+i));
  }
printf("the Entred values are\n ");
for ( i = 0; i <n ; i++) {
    printf("%d\t",*(ptr+i));
}
     printf("enter updated value of n ::");
     scanf("%d",&n1);
   int * ptr1 =(int*)realloc(ptr,n1*sizeof(int));
     
    // printf ("previous address %u ,new address %u \n",ptr ,ptr1);
    if (n1>n) 
    {
            n2=n1-n;
          printf ("enter %d new value ",n2);
          for ( i = 0; i <n2 ; i++)
           { 
              scanf("%d",*(ptr+n+i));
          
          }
    }
printf("Entred(updated) values are\n ");
for ( i = 0; i <n ; i++) {
    printf("%d\t",*(ptr+i));
}

free (ptr1);
return 0;
}



