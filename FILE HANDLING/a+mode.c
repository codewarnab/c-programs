#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char ch;
    char str[50];
    fp = fopen("strinoutput.txt", "a+");

    if (fp == NULL)
    {
        printf("error ");
        exit(1);
    }
    fputs("this is awesome\n", fp);
    rewind(fp);
    // n C programming language, the feof() function is used to check if the end-of-file (EOF) indicator associated with a file stream has been set. It returns a nonzero value if the EOF indicator is set, indicating that the end of the file has been reached, and 0 otherwise.
    while (!feof(fp))
    {
        ch = fgetc(fp);
        printf("%c", ch);

        /* code here */
    }
    // printf("\n");
    return 0;
}