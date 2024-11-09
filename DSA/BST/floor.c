// The floor of a given key in a Binary Search Tree (BST) is defined as the largest value in the tree that is less than or equal to the key
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

struct node *findfloor(struct node *root, int key)
{
    struct node *floor = NULL;
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root; // exact match , return the node as the floor
        }
        else if (key > root->data)
        {                 // incase of ceil its < and incase of floor its >
            floor = root; // possible floor found , move to the right subtree
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return floor;
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
    struct node *floorNode = findfloor(root, key);

    if (floorNode != NULL)
    {
        printf("Floor of %d is %d.\n", key, floorNode->data);
    }
    else
    {
        printf("No floor found for %d in the BST.\n", key);
    }

    return 0;
}