#include <stdio.h>
#include <stdlib.h>

int *x;                // Solution vector
int n;                 // Number of queens
int solutionCount = 0; // To track total solutions found

// a) Function to read number of queens
void read()
{
    printf("Enter the number of queens (N): ");
    scanf("%d", &n);
    x = (int *)malloc((n + 1) * sizeof(int)); // Allocate memory for x[1..n]
}

// Checks if a queen can be safely placed at row k, column i
int place(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0; // Conflict: same column or diagonal
    }
    return 1; // Safe to place
}

// c) Displays the current solution
void display()
{
    solutionCount++;
    printf("\nSolution %d:\n", solutionCount);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
                printf(" Q ");
            else
                printf(" - ");
        }
        printf("\n");
    }
}

// b) Recursive backtracking function to place queens
void queen(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
                display(); // All queens placed
            else
                queen(k + 1); // Recur for next row
        }
    }
}

int main()
{
    read();
    printf("\nSolving %d-Queen problem using Backtracking\n", n);
    queen(1);
    if (solutionCount == 0)
        printf("No solution exists for N = %d\n", n);
    free(x); // Free allocated memory
    return 0;
}
