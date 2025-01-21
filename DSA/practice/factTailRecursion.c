#include <stdio.h>

int factorialtailrecursion(int n , int accumulator){
    if ( n==0 || n == 1 ){
        return accumulator;
    }

    return factorialtailrecursion(n - 1, n * accumulator);
}

int factorial(int n){
    return factorialtailrecursion(n, 1); // start with acc as 1 
}

int main()
{
    int number = 5; // Example input
    printf("Factorial of %d is %d\n", number, factorial(number));
    return 0;
}
