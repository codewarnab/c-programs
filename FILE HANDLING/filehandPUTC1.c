// program to create file AND ENTER CHARECTER
#include <stdio.h>
#include <stdlib.h> //EXIT() IS DECLARED HERE

void main()
{
     FILE *fp = NULL; // FILE IS A DATA TYPE WHICH IS  IN CAPITAL
     char ch = 'P';
     fp = fopen("abc.txt", "w"); // HERE "W" MEANS WRITE .
     // HERE THIS FUNTON WILL FIRST CREATE THE FILE THEN IT WILL WRITE
     if (fp == NULL)
     {
          printf("error ");
          exit(1);
     }
     fputc(ch, fp); // this funtion is used to put a charecter into a file
     fclose(fp);
}