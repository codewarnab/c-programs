#include <stdio.h>
#include <stdlib.h>

void fibbo_nacci(int n)
{
    if (n < 0)
    {
        printf("Please enter a positive number ");
        return;
    }
    int *fib = (int *)malloc(n * sizeof(int));
    if (fib == NULL)
    {
        printf("Memory allocation failed ");
        return;
    }

    // ******** Bottom-Up Approach Explanation ********
    // - Starts with the smallest subproblems (base cases) first.
    // - Base cases are defined:
    //     fib[0] = 0 (the first Fibonacci number)
    //     fib[1] = 1 (the second Fibonacci number, if n > 1)
    // - Uses these base cases to iteratively build up to the desired result.
    // - For each i from 2 to n-1, computes fib[i] as the sum of the two previous values:
    //     fib[i] = fib[i-1] + fib[i-2]
    // - This method avoids recursion and redundant calculations, ensuring efficient performance.   
    fib[0] = 0;
    if (n > 1)
    {
        fib[1] = 1;
    }

    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    printf("Fibbonacci series is ..\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", fib[i]);
    }
    printf("\n");

    free(fib);
}

int main()
{
    int n;
    printf("Enter value of n : ");
    scanf("%d", &n);
    fibbo_nacci(n);
}