// we want the smallest node value in the tree that is greater than or equal to the given key.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

struct node *findceil(struct node *root, int key)
{
    struct node *ceil = NULL; // if no ceiling exists eg if the key is larger than all the values in the tree it will remain NULL

    while (root != NULL)
    {
        if (root->data == key)
        {
            return root; // exact match , return the node
        }
        else if (key < root->data)
        {
            ceil = root; // Possible ceiling found , move to left subtree
            root = root->left;
        }
        else
        {
            root = root->right; // Move to right subtree
        }

        return ceil;
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int key = 55;
    struct node *ceilNode = findceil(root, key);

    if (ceilNode != NULL)
    {
        printf("Ceiling of %d is %d.\n", key, ceilNode->data);
    }
    else
    {
        printf("No ceiling found for %d in the BST.\n", key);
    }

    return 0;
}
