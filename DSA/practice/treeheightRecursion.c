#include <stdio.h>
#include<stdio.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node; 

Node *createNode (int data ){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode; 
}

int treeHeight(Node *root){
    if(root == NULL ){
        return 0;// Base case : Height of an empty tree is 0 
    }

    // recursively find the height the left and right subtrees
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    //  Height of the tree is 1 + maximum of the leftHeight and rightHeigt

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);

}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("Height of the tree: %d\n", treeHeight(root));
    return 0;
}
