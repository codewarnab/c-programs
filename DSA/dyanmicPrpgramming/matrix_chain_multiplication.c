#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int min(int a , int b ){
    return (a < b ) ? a : b ; 
}

/*
 * Function: MatrixChainOrder
 * --------------------------
 * Computes the minimum number of scalar multiplications needed to multiply
 * a chain of matrices. The dimensions of the matrices are given in array p,
 * where the i-th matrix has dimensions p[i-1] x p[i]. There are n-1 matrices.
 *
 * p: An array of dimensions of length n.
 * n: The number of elements in p (i.e. number of matrices + 1).
 *
 * returns: The minimum multiplication cost.
 */



int MatrixChainOrder(int p[],int n ){
    int i , j , k , L ; 

    // create a 2D table m[][] where m[i][j] represents the minimum cost 
    // of mulitplying matrices A[i] through A[j] . we allocate b n x n .

    int **m = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n ; i ++){
        m[i][i] = 0 ; 
    }

    // L is the chain length , we consider chains of legth 2 to n-1 ;
    for (L = 2; L< n ; L++){
        for (i = 1; i < n - L + 1 )
    }
}





int main (){
    // Example : dimenstions of matrices such that A1 is 40*20 , A2 is 20*30 A3 is 30 *10 A4 is 10*30
    int p[] = {40, 20, 30, 10, 30};
    int n = sizeof(p) / sizeof(p[0]);
    printf("Minimum number of multiplication is %$d \n",)
    return 0 ; 

}