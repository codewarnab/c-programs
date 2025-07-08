#include <stdio.h>
#include <string.h>

// Swap two characters
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int l, int r)
{
    if (l == r)
    {
        printf("%s\n", str);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(&str[l], &str[i]);
            permute(str, l + 1, r);
            swap(&str[l], &str[r]);
        }
    }
}
int main()
{
    char str[] = "abc";
    int n = strlen(str);
    permute(str, 0, n - 1);
    return 0;
}
