// You are given coins of different denominations and a total amount of money `amount`.Write a function to compute the fewest number of coins that you need to make up that amount.If that amount of money cannot be made up by any combination of the coins,
//return `- 1`.

//You may assume that you have an infinite number of each kind of coin.

#include<stdio.h>
#include<stdlib.h>


int coinChange(int *coins , int coinSize , int amount){
    // Allocate dp array of size amount + 1
    int *dp = malloc((amount + 1) * sizeof(int)); 
    if(dp == NULL){
        printf("Memory allocation failed .\n");
    }

    // Initialize dp array with a value larger than any valid answer .
    // amount + 1 is a 
}
