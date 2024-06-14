// this program is to get back file pointer  to beginning
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   FILE *fp = NULL;
   char ch;
   char str[50];
   fp = fopen("strinoutput.txt", "r+");
   if (fp == NULL)
   {
      printf("error ");
      exit(1);
   }
   fseek(fp, 0, SEEK_SET);
   while (!feof(fp))
   {
      ch = fgetc(fp);
      printf("%c", ch);
      /* code here */
   }
}