#include <stdio.h>
#include <stdlib.h>

int *x; // solution vector
int n;  // number of queens

// a) Function to read number of queens
void read()
{
    printf("Enter the number of queens(N): ");
    scanf("%d", &n);
    x = (int *)malloc((n + 1) * sizeof(int)); // x[1..n]
}

/*
 * Function: place
 * ----------------------------
 *   Checks if a queen can be placed at row k, column i
 *
 *   k: current row where we want to place a queen
 *   i: candidate column for the queen
 *
 *   Returns 1 if no conflict, 0 otherwise.
 */
// Checks if a queen can be safely placed at row k, column i
int place(int k, int i)
{
    // Try every previously placed queen at row j (1..k-1)
    for (int j = 1; j < k; j++)
    {
        // 1) Column check:
        //    If any earlier queen is already in column i, it's a conflict.
        /**
         * @brief Represents the positions of queens on a chessboard for the N-Queens problem.
         *
         * The integer array `x` maps each row to the column index where its queen is placed:
         *   - `x[j]` stores the column number for the queen in row j.
         *
         * Example:
         *   If `x[3] == 5`, there is a queen at row 3, column 5.
         */
        if (x[j] == i)
        {
            return 0; // same column → cannot place
        }

        // 2) Diagonal check:
        //    Two queens are on the same diagonal if
        //    the difference in their row indices equals
        //    the difference in their column indices.
        //
        //    |column_j - column_i| == |row_j - row_k|
        if (abs(x[j] - i) == abs(j - k))
        {
            return 0; // diagonal conflict → cannot place
        }
    }

    // No conflicts found: it is safe to place the queen at (k, i)
    return 1;
}
/*
 * Function: queen
 * ----------------------------
 *   Recursive backtracking routine to place queens row by row
 *
 *   k: current row to place the queen
 */
void queen(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
                display(); // c ) show solution when all queens placed
            else
                queen(k + 1);
        }
    }
}

void display()
{
    printf("\nSolution:\n");
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

int main()
{
    read();
    printf("\nSolving %d-Queen problem using Backtracking\n", n);
    queen(1);
    free(x); // free the allocated memory
    return 0;
}