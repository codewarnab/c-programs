#include <stdio.h>

// Function to calculate factorial
unsigned long long factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int number;
    unsigned long long result;

    // Asking user to enter a number
    printf("Enter a number to find its factorial: ");
    scanf("%d", &number);

    // Checking if the entered number is non-negative
    if (number < 0)
    {
        printf("Factorial of a negative number doesn't exist.\n");
    }
    else
    {
        result = factorial(number);
        printf("Factorial of %d is %llu\n", number, result);
    }

    return 0;
}
