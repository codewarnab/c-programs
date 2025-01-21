#include <stdio.h>

int gcd(int a , int b ){
    if (b == 0 )
        return a;

    gcd(a, a % b);
}

int main()
{
    int num1 = 56, num2 = 98; // Example input
    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    return 0;
}
