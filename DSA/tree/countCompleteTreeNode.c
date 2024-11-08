// count complete tree node 
// https://youtu.be/u-yWemKGWO0?si=RtHrs5GYndB3FZQk

// Complete binary tree properties
// All levels are completely filled except possibly the last, which is filled from left to right.
// if a subtree is a perfect binary tree ( where all levels are fully filled ), the number of nodes is 2^height - 1 and we can calculate without recursion 

// Approach 
// .. Calculate the left most and right most depths of the tree 
// If both depths are the same  , the tree is a perfect binary  tree and the node count is 2^depths - 1 
// if the depths are diffreent , recursivley calculate the  number of nodes in the left

// The recursive nature of this approach, combined with the logarithmic depth calculations, results in a time complexity of O(log^2N)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// defintion of a tree node 

struct node {
    int data ;
    struct node *right, *left;
};

struct node * createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->left = newNode->right = NULL;

    return newNode; 
}

int leftDepth(struct node * node ){
    int depth = 0; 
    while(node){
        depth++;
        node = node->left; 
    }
    return depth; 
}

// Function to calculate the depth of the rightmost path 

int rightDepth(struct node * node ){
    int depth = 0 ; 
    while(node){
        depth++;
        node = node->right ; 
    }
    return depth; 
}

// Recursive function to count nodes in a complete binary tree 

int countNodes(struct node* root){
    if (root == NULL)
        return 0;

    int left_depth = leftDepth(root);
    int right_depth = rightDepth(root);

    if(left_depth == right_depth){
        return (1 << left_depth) - 1; // (2^left_depth ) -1 
    }else {
        // otherwise , recursively count nodes in the left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

}

int main()
{
    // Create a complete binary tree
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    // Count the total number of nodes
    int totalNodes = countNodes(root);
    printf("Total nodes in the complete binary tree: %d\n", totalNodes);

    return 0;
}