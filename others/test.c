#include<stdio.h>

int main()
{ int a=34 ;
      int * ptr = &a;
      printf("%u  %u",&*ptr,*&ptr);
      
      
       return 0;
}