#include<stdio.h>
#include<string.h>

// Function to reverse a string using recursion  
void reverseString(char str[],int start , int end ){
    // Base case : when starting value is greater than or equal to the end value 

    if ( start >= end  ){
        return;
    }

    char temp = str[start]; 
    str[start] = str[end];
    str[end] = temp;

    reverseString(str, start + 1, end - 1);
}

void reverse(char str[])
{
    int n = strlen(str);
    reverseString(str, 0, n - 1);
}