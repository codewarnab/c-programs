#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
void movechar(char *s);
int  main ()
{ char str[50];
    printf("enter any string ");
    gets(str);
    movechar(str);

}
void movechar(char *s)
{  for (int i=0;s[i]!='\0' ; i++) {
s[i]=s[i]+2;
}
for (int i=0;s[i]!='\0'; i++) {
    printf("%c",s[i]);
}
}
