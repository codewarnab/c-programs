// Breath First Search is an algorithm for traversing or searching a graph . It explores all vertices at the present depth level before moving on to vertices at the next depth leve; . BFS is useful for finding the shortest path in  unweighted graphs and checking connectivoty in componentnts .

// How BFS works

// 1 Start at a source vertex and visit it
//  2 Enqueue the starting vertex  and mark it as visited
//  Iterativley:
//   Dequeue a vertex from the queue .
//  Visit all its adjaacent (or neighbouring) vertices that havnt been visited
//  Mark each of these neighbours as visited and enqueue them
//  continue until the queue is empty

// Example
//       0
//      / \
//     1   2
//    / \
//   3   4

// if we start BFS from vertex 0 , the traversal order will be 0 -> 1 -> 2 -> 3 -> 4

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5

struct Node
{
    int vertex;
    struct Node *next;
};

// A graph with an array of adjacency lists
struct Graph
{
    struct Node *adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
};

// Function to create a new node
struct Node *createNode(int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph *createGraph()
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Initialize all vertices as not visited
    }
    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// BFS algorithm
void bfs(struct Graph *graph, int startVertex)
{
    // Queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the starting vertex as visited and enqueue it
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    // Loop until the queue is empty
    while (front < rear)
    {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        struct Node *temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;

            // If an adjacent vertex has not been visited, mark it visited and enqueue it
            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    struct Graph *graph = createGraph();
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    printf("BFS traversal starting from vertex 0:\n");
    bfs(graph, 0);

    return 0;
}
