// Level order traversal

// start at the root node .
// use a queue to keep track of nodes at each level
// for each node , print its data , then enqueue its left and right children ( if they exists ).
// continue until the queue is empty

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

// This represents a single  node within the Queue
// Each QueueNode holds a pointer to a treeNode (the actual node from the binary tree ) and a pointer to the next QueueNode in  the queue
struct QueueNode
{
    struct node *treeNode;
    struct QueueNode *next;
};

// queue structure to hold tree for level-order traversal
// this represhents the queue as a whole and keeps track of the front and rear of the queue .
// front points to the first QueueNode (node that will be dequeued next )
// rear points to the last QueueNode ( node where new elements are enqueueed )
struct Queue
{
    struct QueueNode *front, *rear;
};

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Adds  a new treeNode to end of the queue
// 1. create a new QueueNode `temp` and assign it the treeNode data
// 2 . if the queue is empty ( rear is NULL ) , set both front and rear to temp
// 3 . if the queue is not empty , link `temp` to the end of the queue by setting rear->next to `temp` and update rear to `temp`;
void enqueue(struct Queue *queue, struct node *treeNode)
{
    struct QueueNode *temp = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = queue->rear = temp;
        return;
    }
    queue->rear->next = temp; // makes the current rear node`s next pointer point to the new node (temp) , linking it as the next node in the queue

    // updates rear to point temp , making temp the new last node in the queue
    queue->rear = temp;
}

// Dequeue function: Removes the front node from the queue and returns its treeNode data.
// 1. If the queue is empty (front is NULL), return NULL.
// 2. Store the current front node in a temporary pointer `temp`.
// 3. Move front to the next node; if the queue is now empty, set rear to NULL.
// 4. Retrieve treeNode data from `temp`, free `temp`, and return the data.

struct node *dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        return NULL;
    }
    struct QueueNode *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    struct node *treeNode = temp->treeNode;
    free(temp);
    return treeNode;
}



int isQueueEmpty(struct Queue* queue){
    return queue->front == NULL;
}


void levelOrder(struct node *root)
{
    if (root == NULL)
        return;

    // create a queueu to hold nodes
    struct Queue *queue = createQueue();

    enqueue(queue, root);

    while(!isQueueEmpty(queue)){
        // Dequeue a node and print its data
        struct node *current = dequeue(queue);
        printf("%d", current->data);

        // enqueue the left child 
        if(current->left != NULL){
            enqueue(queue, current->left);
        }

        // Enqueue the right child 
        if(current->right !=NULL){
            enqueue(queue, current->right);
        }

    }

    free(queue);
}

int main()
{
    // Create a binary tree
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}