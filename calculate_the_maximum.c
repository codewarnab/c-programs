#include "calculate_the_maximum.h"

int calculate_and_max(int n, int k)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int a = i & j;
            if (a > max && a < k)
            {
                max = a;
            }
        }
    }
    return max;
}

int calculate_or_max(int n, int k)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int a = i | j;
            if (a > max && a < k)
            {
                max = a;
            }
        }
    }
    return max;
}

int calculate_xor_max(int n, int k)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int a = i ^ j;
            if (a > max && a < k)
            {
                max = a;
            }
        }
    }
    return max;
}
