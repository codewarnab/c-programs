// screnerios in deletion 
//1. Node with no children (leaf node ):
// if the node to delete has no children , it is a leaf node and we simply delete it 

// 2.Node with one child :
// if the node to delete has one child , we bypass it by linking its parent directly to its child 

// 3 . Node with two children 
// for nodes with two children , we need to find wither the in-order successor (the smallest node in its right subtree)

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};


struct node* createNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data ; 
    newNode->left = newNode->right = NULL;

    return newNode;
}

struct node * insert(struct node* root , int data){
    if(root == NULL){
        return createNode(data);
    }

    if(data < root->data ){
        root->left = insert(root->left , data );
    }else if (data > root->data){
        root->right = insert(root->right, data);
    }

    return root;
}

// helper function to find minimum value node in a tree 
struct node* findMin(struct node* root){
   struct node * current = root ; 
   while (current && current->left != NULL ){
       current = current->left;
   }

   return current; 
}

// FUnction to delete a node in the BST 

struct  node * deleteNode(struct node* root , int key )
{
    if(root == NULL) {
        return root; 
    }

    // Traverse to find the node to delete 
    if(key > root->data){
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node with only one child  or no child 
        if(root->left == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }else if (root->right == NULL){
            struct node * temp = root->left ;
            free(root);

            return temp ; 
        }

    //Node with two children : Get the inorder successor 
    struct node *temp = findMin(root->right);

    // copy the inorder succesor s data to this node
    root->data = temp->data; 

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->data);
    }

    return root; 
};


void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);

    }

}

// Main function to test the delete functionality
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

    printf("In-order traversal of the original tree: ");
    inorder(root);
    printf("\n");

    printf("Deleting 20\n");
    root = deleteNode(root, 20);
    printf("In-order traversal after deleting 20: ");
    inorder(root);
    printf("\n");

    printf("Deleting 30\n");
    root = deleteNode(root, 30);
    printf("In-order traversal after deleting 30: ");
    inorder(root);
    printf("\n");

    printf("Deleting 50\n");
    root = deleteNode(root, 50);
    printf("In-order traversal after deleting 50: ");
    inorder(root);
    printf("\n");

    return 0;
}