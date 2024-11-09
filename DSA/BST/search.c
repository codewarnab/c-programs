#include<stdio.h>
#include<stdlib.h>

struct node {
    int data ; 
    struct node *left , *right ;
};

struct node * createNode(int data ){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}


struct node* insert(struct  node *root , int data){
    if(root == NULL){
        return createNode(data);
    }

    if(data<root->data){
        root->left = insert(root->left, data);
    }else if (data > root->data ){
        root->right = insert(root->right, data);
    }

    return root;
}

struct node* search(struct node* root, int key){
    // Base Case : root is NULL or key is present at root 
    if(root == NULL || root->data == key ){
        return root; 
    }
    // key is greater than root`s data 
    if(key>root->data){
        return search(root->right, key);
    }

    // key is smaller than roots data
    return search(root->left, key);
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

    int key = 40;
    struct node *result = search(root, key);

    if (result != NULL)
    {
        printf("Node with value %d found in the BST.\n", result->data);
    }
    else
    {
        printf("Node with value %d not found in the BST.\n", key);
    }

    return 0;
}