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

// Function to check if two trees are identical
int areIdentical(struct node *root1, struct node *root2)
{
    // Base case: Both trees are empty
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }

    // If both trees are non-empty, check if data matches and recurse for left and right subtrees
    if (root1 != NULL && root2 != NULL)
    {
        return (root1->data == root2->data) &&
               areIdentical(root1->left, root2->left) &&
               areIdentical(root1->right, root2->right);
    }

    // If one tree is empty and the other is not, they are not identical
    return 0;
}

// Main function for testing
int main()
{
    // Create first binary tree
    struct node *root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);

    // Create second binary tree
    struct node *root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);

    // Check if the two trees are identical
    if (areIdentical(root1, root2))
        printf("The trees are identical.\n");
    else
        printf("The trees are not identical.\n");

    return 0;
}
