// CONCATINATION OF TWO STRINGS USING POINTER
#include <stdio.h>
#include <conio.h>
#include <string.h>
int  main ()
{
    char str1[100]="arnab ";
    char str2[100]="mondal";
char *ps1,*ps2;
ps1=str1;
ps2=str2;
while (*PS1!='\0')
  {
    ps1++;
   }
 for (;*ps2!='\0';ps2++,ps1++)
 {

    *ps1=*ps2;


  }
*ps1='\0';
puts(str1);
return 0;
}