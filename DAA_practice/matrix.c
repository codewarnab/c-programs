// https://claude.ai/chat/b015efac-1d8d-4bee-9a88-5cfeef9141ec
// explanation in detail
#include <stdio.h>
#include <limits.h>

// Function to generate the cost matrix
void costmatrix(int p[],int n , int m[n][n], int s[n][n]  ){
    for (int i = 0; i < n; i++){
        m[i][i] = 0; 
    }

    for (int chainlen = 2; chainlen < n; chainlen++){
        for (int i = 1; i < n - chainlen + 1; i++){

            int j = chainlen + i - 1;

            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++){
                int q = m[i][k] + m[k+1][i] + p[i-1]*p[i] * p[j] ; 

                if(q<m[i][j]){
                    m[i][j] = q; // store the minimum costr
                    s[i][j] = k; // store the optimal split point 
                }
            }
        }
    }
}

void optimalsequence(int s[6][6], int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        optimalsequence(s, i, s[i][j]);
        optimalsequence(s, s[i][j] + 1, j);
        printf(")");
    }
}

void optimalsequence(int s [6][6], int i , int j ){
    if(i ==j){
        printf("A%d",i);
    }
    else {
        printf("(");
        optimalsequence(s, i, s[i][j]);
        optimalsequence(s, s[i][j] + 1, j);
        printf(")");
    }
}


void mutliplication(int p[], int n)
{
    int m[6][6], // m[i][j] will hold the minimum cost (number of scalar multiplications)
        s[6][6]; // s[i][j] will hold the k-index where the optimal split occurs

    costmatrix(p, n, m, s);
    printf("\n Minimum number of multiplication is %d\n", m[1][n - 1]);

    printf("Optimal Parenthesization is: ");
    optimalsequence(s, 1, n - 1);
    printf("\n");
}

int main()
{
    // Dimenstions : A(4x10) ,B(10x3), C(3x12) ,D(12x20) , E(20x7)
    int p[] = {4, 10, 3, 12, 20, 7};
    int n = sizeof(p) / sizeof(p[0]);
    multiplication(p, n);

    return 0;
}