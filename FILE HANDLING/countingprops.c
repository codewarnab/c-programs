/*this program is to calculate number vowels blank spaces
and number of new lines */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  int v, b, n;
  v = 0;
  b = 0;
  n = 1;
  char ch;
  FILE *fp;
  fp = fopen("strinoutput.txt", "r");
  if (fp == NULL)
  {
    printf("error cant open file ");
  }
  printf("CONTENT OF THE FILE :\n");
  while (!feof(fp))
  {
    ch = fgetc(fp);
    printf("%c", ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' ||
        ch == 'o' || ch == 'u' || ch == 'A' ||
        ch == 'E' || ch == 'I' || ch == 'O' ||
        ch == 'U')
    {
      v++;
    }
    if (ch == ' ')
    {
      b++;
    }
    if (ch == '\n')
    {
      n++;
    }
  }
  printf("\n");
  printf("desciption of content :\n");
  printf("NUmber of vowels are %d\n", v);
  printf("NUmber of blank spACES  are %d\n", b);
  printf("NUmber of lines  are %d\n", n);

  printf("\n");
  return 0;
}