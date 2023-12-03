// Author = Arnab MOndal 
// date = 27 th may 2022
//checking if we can change the value of static variable 

#include <stdio.h>

int main () {
static int d= 423;
printf("%d\n",d);
d = 23;
printf("%d\n",d);

    return 0;
}
// so result is we can reiniliatise static variables 
