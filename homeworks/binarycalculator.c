// this is a program to do all binary operations 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void btod();
void dtob();
int main ( ) 
    {  int op;
        printf("which funtion you want to use ?\n");
        printf("1.BINARY -->DECIMAL\n2.DECIMAL-->BINARY\n");
        printf("Enter corresponded number : ");
        scanf("%d",&op);
        switch (op)
        { case 1: 
        btod();
        break;
         case 2: 
        dtob();
        break;
        default:
        printf("error wront input ");
            break;
        }

    return 0;
}
// DECIMAL TO BINARY CONVERSTION 
void dtob()
{

    int n,i=0,arr[100],arr1[100],rem; float num,n2;
    printf("Enter any decimal number  ");
    scanf("%f",&num);
     n=(int)num;
     n2=num-n;
    //for integer part of the number  
    while(n)
    {    i++;
        rem=n%2;
        arr[i]=rem;
        n=n/2;
 
    }
    for (; i > 0; i--) {
        printf("%d",arr[i]);
    }
    // checking number is float or not 
    if ((num-(int)num)!=0) 
    {
    printf(".");
    }
// for fractional part of the number  
int j=0;i=0;
float s ;
while (n2)
{
    i++;
    arr1[i] = (int)(n2*2);
    n2=  n2*2-arr1[i];
}
j=i;
for ( i = 1; i <= j ; i++) {
printf("%d",arr1[i]);
}
printf("\n");
}

// BINARY TO DECIMAL CONVERSTION 
void btod() {
long int binum,decinum=0;
printf("Enter any binary number :");
scanf("%ld",&binum);
/* count binum of digits */
int c = 0; /* digit position */
int n = binum;
while (n != 0)
{
    n /= 10;
    c++;
}
int numberArray[c];
c = 0;    
n = binum;
/* extracting each digit */
while (n != 0)
{
    numberArray[c] = n % 10;
    n /= 10;
    c++;
}
for (int i = c-1; i >=0; i--) {
    decinum+= numberArray[i]*(pow(2,i));
}
printf("decimal equiavalent is %d\n",decinum);
}   