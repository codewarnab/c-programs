// Breath First Search is an algorithm for traversing or searching a graph . It explores all vertices at the present depth level before moving on to vertices at the next depth leve; . BFS is useful for finding the shortest path in  unweighted graphs and checking connectivoty in componentnts . 

// How BFS works 

//1 Start at a source vertex and visit it 
// 2 Enqueue the starting vertex  and mark it as visited 
// Iterativley:
//  Dequeue a vertex from the queue .
// Visit all its adjaacent (or neighbouring) vertices that havnt been visited 
// Mark each of these neighbours as visited and enqueue them 
// continue until the queue is empty 

// Example 
//       0
//      / \
//     1   2
//    / \
//   3   4

// if we start BFS from vertex 0 , the traversal order will be 0 -> 1 -> 2 -> 3 -> 4 

#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 5 

struct Node {
    int vertex;
    struct Node *next;
};

// A graph with an array of adjacency list 
struct Graph {
    struct Node *adjLits[MAX_VERTICES];
};

// Function to create a new Node 

struct Node* createNode(int dest){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->
}