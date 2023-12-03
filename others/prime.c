
// program  to chrck prime or not 
#include <stdio.h>
int main (int argc, char *argv[]) {
 
int flag=0,n;
printf("Enter the number you want to check : ");
scanf("%d",&n);
for (int i = 2; i < n/2; i++) {
    if (n%i==0)
    {
        flag = 1;
        break;
    }
}
    if (flag==0)
    printf("This is a prime number ");
    else 
    printf(" this is a composite number ");

 
 
    return 0;
}