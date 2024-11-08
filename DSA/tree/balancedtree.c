#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node
{
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Helper function to check for balanced tree and calculate height
int checkHeight(struct node *root)
{
    // Base case: an empty tree has height 0 and is balanced
    if (root == NULL)
        return 0;

    // Check the height of the left subtree
    int leftHeight = checkHeight(root->left);
    // If the left subtree is unbalanced, propagate -1 up the call stack
    if (leftHeight == -1)
        return -1;

    // Check the height of the right subtree
    int rightHeight = checkHeight(root->right);
    // If the right subtree is unbalanced, propagate -1 up the call stack
    if (rightHeight == -1)
        return -1;

    // If the difference in height between left and right subtrees is more than 1, the tree is unbalanced
    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    // If balanced, return the height of the current node as 1 + max(leftHeight, rightHeight)
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Main function to check if the tree is balanced
int isBalanced(struct node *root)
{
    // If checkHeight returns -1, the tree is unbalanced; otherwise, it's balanced
    return checkHeight(root) != -1;
}

// Main function for testing
int main()
{
    // Create a sample binary tree
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->left = createNode(6); // Adding an extra node to make it unbalanced

    // Check if the binary tree is balanced
    if (isBalanced(root))
        printf("The tree is balanced.\n");
    else
        printf("The tree is not balanced.\n");

    return 0;
}
 