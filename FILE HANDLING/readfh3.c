#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE *fp = NULL;
  char ch;
  fp = fopen("strinoutput.txt", "r"); // here 'r' represents read mode
  // Here, the file must already exist for reading. If not, fp will be NULL.
  if (fp == NULL)
  {
    printf("error");
    exit(1);
  }
  while (!feof(fp))
  {                 // check if it is end-of-file or not after moving the cursor
    ch = fgetc(fp); // We read characters from the file one by one and store them in 'ch' to print
    printf("%c", ch);
    /* code here */
  }
  /* 'feof' function indicates the end of the file. It returns true or false value.
  When it reaches the end of the file, it will return true and the loop will stop, so we use '!' to make it false. */
  /* To read the first character, just use 'fgetc()' without the loop */
  /* 'fgetc()' is used to obtain input from a file one character at a time. This function returns the ASCII code of the character read by the function. It returns the character present at the position indicated by the file pointer. After reading the character, the file pointer is advanced to the next character.*/
  fclose(fp);
}
