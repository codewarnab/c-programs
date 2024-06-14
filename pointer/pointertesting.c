#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a = 121;
    int *ptr1, **ptr2, ***ptr3;
    ptr1 = &a;
    printf("ptr1 = %p\n", ptr1);
    printf("content at ptr1 = %d \n", *ptr1);
    // printf("ptr1 = %p\n",*ptr1+1);
    ptr2 = &ptr1;
    printf("ptr2 = %p\n", *ptr2);
    printf("content at ptr2 = %d \n", **ptr2);
    ptr3 = &ptr2;
    printf("ptr3 = %p\n", **ptr3);
    printf("content at ptr3 = %d\n", ***ptr3);

    return EXIT_SUCCESS;
}