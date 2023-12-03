// program to calculate elapsed time 
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <limits.h>
void main ()
{   printf(" INT MAX= %llu\n",INT_MAX);
    double tick1,tick2,et;
    tick1= clock();
    for (int i=0; i<INT_MAX; i++)
    {}
    tick2= clock();
    double e = tick2- tick1;
    et= (double)e/CLOCKS_PER_SEC;
    printf("ellapsed time = %lf... seconds \n",et);
    //display();
}