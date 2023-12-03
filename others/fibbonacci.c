// program to print fibonacci series 
#include <stdio.h>
// // using for loop 
// int main (int argc, char *argv[]) 
// {  int n1=0,n2=1,n3,n;
//    printf("Enter the number ");
//    scanf("%d",&n);
//    printf(" %d %d ",n1,n2);
//    for (int i = 2; i < n; i++) {
//  n3 = n1+n2 ;
//  printf("%d ",n3);
//  n1 = n2 ;
//  n2 = n3 ;
//    }
   
//     return 0;
// }
// // using array 
// #include<stdio.h>
//  void main()
//  {  int i, fib[25]; 
// fib[0] = 0; 
//  fib[1] = 1; 
//  for (i = 2; i < 10; i++) 
// {  fib[i] = fib[i - 1] + fib[i - 2]; }
//  printf("The fibonacci series is as follows "); 
//  for (i = 0; i < 10; i++) 
//  { printf("%d ", fib[i]);
//  } 
// }
// // using recursion 
// #include<stdio.h>
// int f(int);
// int main()
// {
// int n, m= 0, i;
// printf("Enter Total terms:n");
// scanf("%d", &n);
// printf("Fibonacci series terms are:n");
// for(i = 1; i <= n; i++)
// {
// printf("%d ", fibonacci(m));
// m++;
// }
// return 0;
// }
// int fibonacci(int n)
// {
// if(n == 0 || n == 1)
// return n;
// else
// return(fibonacci(n-1) + fibonacci(n-2));
// }
