#include<stdio.h>
#include<string.h>

int main()
{
    
    
    FILE *fp;
    
    char str[80],c;
    fp = fopen("strinoutput.txt","r+");
    if (fp == NULL)
    {
       printf("File cannot be opened ");
       return 0;
    }
    fclose(fp);
    fp = fopen("strinoutput.txt", "a+");
    printf("Enter The string : \n");
    gets(str);
    fputs(str,fp);
   
    fclose(fp);
 }
    