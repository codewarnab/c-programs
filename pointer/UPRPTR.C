// string uppercase using pointer
#include <stdio.h>
#include <conio.h>
#include <string.h>
int  main ()
{ char str[100],*ps;
   printf ("enter any string :: ");
   gets(str); int len = strlen(str);
   ps = str ;
//  for (int i =0;i<len ; i++)
 for (;*ps!='\0';)

 {
    if (*ps >= 'a' && *ps <='z')
    {
        *ps=*ps-32 ;
    }
    ++ps;
 }
 puts(str);
}
 