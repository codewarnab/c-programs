#include <stdio.h>

void towerOfHanoi(int n , char source , char desitinion , char auxilary ){

    // Base case : if only one disk , move it directly 

    if(n==1){
        printf("Move disk 1 from %c to %c\n", source, desitinion);
        return; 
    }

    // move n-1 disks from source to auxilary using desitinion as auxilary

    towerOfHanoi(n - 1, source, auxilary, desitinion);

    // move the nth disk from source to destinion
    printf("Move disk %d from %c to %c\n",n,source, desitinion);

    // Move n-1 disks from auxilary to desitination using source as auxilary
    towerOfHanoi(n - 1, auxilary, desitinion, source);
}











int main(){
    int n;

    printf("Enter the  number of disks: ");
    scanf("%d", &n);

    printf("The moves involved are :\n");
    towerOfHanoi(n, 'A', 'C', 'B'); // 'A' is the source , c is the destiniion and be is the auxilary peg 
}