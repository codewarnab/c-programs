// this program is to copy content of one file to another
// file
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp1 = NULL;
    char c;
    FILE *fp2 = NULL;
    fp1 = fopen("file1.txt", "r+");
    if (fp1 == NULL)
    {
        printf("error ");
        exit(1);
    }

    char str[50];
    fp2 = fopen("file2.txt", "w");
    if (fp2 == NULL)
    {
        printf("error ");
        exit(1);
    }
    while ((c = fgetc(fp1)) != EOF)
    {
        fputc(c, fp2);
    }

    printf("Succesfully copied\n ");
    fclose(fp1);
    fclose(fp2);
}