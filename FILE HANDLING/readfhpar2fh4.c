#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *fp = NULL;
    char ch;
    fp = fopen("strinoutput.txt", "r"); // here r represents the read  mode
    // here file must be created alr4eADY FOR reading if file
    //  is not there fp = NULL
    if (fp == NULL)
    {
        printf("error");
        exit(1);
    }
    while (!feof(fp))
    {
        ch = fgetc(fp); // basically funtion ta jeta read korche ota amra
                        // ch a store nkore print korbo
        printf("%c", ch);
        /* code here */
    }

    fclose(fp);
}