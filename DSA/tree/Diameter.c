#include<stdio.h>
#include<stdlib.h>


struct node {
    int data ; 
    struct node *left , *right ; 
};

struct node * createNode(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node ));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

// Helper function to calculate the height and update the diameter 

int calculateDiamter(struct node * root , int * diameter){
    if(root ==NULL){
        return 0;
    }

    // Recursively get the height of the left and right subtrees
    int leftHeight = calculateDiamter(root->left, diameter);
    int rightHeight = calculateDiamter(root->right, diameter);

    // update the diameter ( maximum diamemter found so far )

    int currentDiameter = leftHeight + rightHeight + 1; 
    if ( currentDiameter > *diameter ){
        *diameter = currentDiameter;
    }

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
 
int getDiameter(struct node * root){
    int diameter = 0 ;
    calculateDiamter(root, &diameter);
    return diameter;
}


