#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// defintion of a tree node

struct node
{
    int data;
    struct node *right, *left;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->left = newNode->right = NULL;

    return newNode;
}

