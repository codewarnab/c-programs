// fseeek funtion is used to move the position of cursor
/*syntax is
fseek(filepointer,offset,position)
return type of this fn  is int */
/*SEEK_END : It denotes end of the file.
SEEK_SET : It denotes starting of the file.
SEEK_CUR : It denotes file pointer’s current position.*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char ch;
    char str[50];
    fp = fopen("strinoutput.txt", "r");
    if (fp == NULL)
    {
        printf("error ");
        exit(1);
    }
    fseek(fp, 6, SEEK_SET);
    ch = fgetc(fp);
    printf("%c\n", ch);
    // for coming backward
    fseek(fp, -3, SEEK_CUR);
    ch = fgetc(fp);
    printf("%c\n", ch);
    fclose(fp);
    return 0;
}