/* return type of ftell funtion is long int */
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
  int pos = ftell(fp);
  printf("%d\n", pos);
  fseek(fp, 6, SEEK_SET);
  pos = ftell(fp);
  printf("%d\n", pos);
  fseek(fp, 7, SEEK_END);
  ch = fgetc(fp);
  printf("%c\n", ch);

  printf("%d\n", ftell(fp));

  return 0;
}