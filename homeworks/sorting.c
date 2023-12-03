#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void bs(int,int*);
int main (){ int n;
printf ("enter how many elements you want to enter:: ");
scanf("%d",&n);
int arr[n];
for (int i = 0; i < n ; i++) {
    /* code here */ printf("arr[%d]=",i);
scanf("%d",&arr[i]);
}
bs(n,arr);
return 0;
}
 void bs(int n,int a[])
{ 
 int i,j,swap;
for (i=0; i<n-1; i++)
    {   int flag =0;
        for (j=0; j<n-1-i; j++)
        {   if (a[j]>a[j+1])
            {   swap = a[j];
                a[j]=a[j+1];
                a[j+1]=swap;
                flag=1;
            }
        }
    }
    printf("sorted array is ");
    for (i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
}


