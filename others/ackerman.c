// C program to illustrate Ackermann function

#include <stdio.h>
int ack(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if ((m > 0) && n == 0)
    {
        return ack(m - 1, n);
    }
    else if ((m > 0) && n > 0)
    {
        return ack(m - 1, ack(m, n - 1));
    }
}

int main()
{
    int A;
    A = ack(2, 6);
    printf("%d", A);
    return 0;
}

// This code is contributed by Amiya Rout
