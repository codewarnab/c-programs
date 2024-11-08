#include <stdio.h>
#include <stdlib.h>

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

// Helper function to check if two trees are mirror images
int areMirror(struct node *tree1, struct node *tree2)
{
    // If both trees are empty, they are mirror images
    if (tree1 == NULL && tree2 == NULL)
        return 1;

    // If only one of the trees is empty, they are not mirror images
    if (tree1 == NULL || tree2 == NULL)
        return 0;

    // Check if the current nodes have the same data, and if the left subtree of one
    // tree is a mirror of the right subtree of the other, and vice versa
    return (tree1->data == tree2->data) &&
           areMirror(tree1->left, tree2->right) &&
           areMirror(tree1->right, tree2->left);
}

// Main function to check if a tree is symmetric
int isSymmetric(struct node *root)
{
    // A tree is symmetric if it is a mirror image of itself
    if (root == NULL)
        return 1;
    return areMirror(root->left, root->right);
}

// Main function for testing
int main()
{
    // Create a symmetric binary tree
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    // Check if the tree is symmetric
    if (isSymmetric(root))
        printf("The tree is symmetric.\n");
    else
        printf("The tree is not symmetric.\n");

    return 0;
}
