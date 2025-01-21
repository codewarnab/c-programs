#include <stdio.h>

// Define the structure for a node

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

// inorder traversal ( Non-Recursive ) using a stack

void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *stack[100]; // stack to simulate recursion

    int top = -1; // stack pointer
    Node *current = root;
    while (current != NULL || top >= 0)
    {
        while (current != NULL)
        {
            stack[++top] = current;  // Push node to stack
            current = current->left; // Move left
        }
        current = stack[top--];// Pop node from stack
        printf("%d", current->data); // Visit node
        current = current->right; // Move right 
    }
}

// Main function 
int main(){

    Node *root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    return 0;
}