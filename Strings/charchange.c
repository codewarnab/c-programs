/* shift each character in a string by two positions in the ASCII table and print the modified string. */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void movechar(char *s);
int main()
{
    char str[50];
    printf("enter any string ");
    gets(str);
    movechar(str);
}
void movechar(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = s[i] + 2;
    }
    puts(s);
    
}
