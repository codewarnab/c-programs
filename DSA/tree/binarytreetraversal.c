// remember for preorder : root left right
// remember for inorder :  left root right
// remember for PostOrder : Left right root
// https://youtu.be/e_Wv_pH4Se8?si=jpp0VLGYahAu1qiF
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

// Function for preorder traversal
void Preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

// Function for inorder traversal
void Inorder(struct node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

// Function for postorder traversal
void Postorder(struct node *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

// Function to build a simple binary tree for demonstration
struct node *buildTree()
{
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    return root;
}

// Menu function
void menu(struct node *root)
{
    int choice;
    do
    {
        printf("\nMenu:\n");
        printf("1. Preorder Traversal\n");
        printf("2. Inorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Preorder traversal: ");
            Preorder(root);
            printf("\n");
            break;
        case 2:
            printf("Inorder traversal: ");
            Inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Postorder traversal: ");
            Postorder(root);
            printf("\n");
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

// Main function
int main()
{
    struct node *root = buildTree(); // Building a simple binary tree
    menu(root);                      // Call the menu function
    return 0;
}
