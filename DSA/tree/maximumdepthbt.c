// find the maximum depth of a binary trr 
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data ; 
    struct node *left , *right ;
};

struct node *createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data ; 
    newNode->left = newNode->right = NULL;

    return newNode;
}

int maxDepth(struct node * root ){
    if(root == NULL){
        return 0;
    }
    else {
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Return the larger depth plus 1 for the current node
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);

    }
}

int main(){
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Maximum depth of the binary tree: %d \n", maxDepth(root));

    return 0 ; 
}