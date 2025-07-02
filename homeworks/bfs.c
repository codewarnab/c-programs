#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Queue structure for BFS
struct Queue
{
    int items[MAX_VERTICES];
    int front;
    int rear;
};

// Graph structure
struct Graph
{
    int vertices;
    int **adjacencyMatrix;
};

// Function prototypes
struct Queue *createQueue();
void enqueue(struct Queue *q, int value);
int dequeue(struct Queue *q);
bool isQueueEmpty(struct Queue *q);
struct Graph *createGraph(int vertices);
void addEdge(struct Graph *graph, int src, int dest);
void bfs(struct Graph *graph, int startVertex, int *visited, int *path, int *pathSize);
void displayBFSPath(int *path, int pathSize);

// Main function to read graph data and start vertex
int main()
{
    int vertices, edges, i, j, src, dest, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    // Initialize visited array and path array
    int visited[MAX_VERTICES] = {0};
    int path[MAX_VERTICES];
    int pathSize = 0;

    // Perform BFS
    bfs(graph, startVertex, visited, path, &pathSize);

    // Display BFS path
    printf("\nBFS Path: ");
    displayBFSPath(path, pathSize);

    // Free allocated memory
    for (i = 0; i < vertices; i++)
    {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);

    return 0;
}

// Create a queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Add element to queue
void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX_VERTICES - 1)
        printf("Queue is full\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Remove element from queue
int dequeue(struct Queue *q)
{
    int item;
    if (isQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        return item;
    }
}

// Check if queue is empty
bool isQueueEmpty(struct Queue *q)
{
    return q->front == -1;
}

// Create a graph with given number of vertices
struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Create adjacency matrix
    graph->adjacencyMatrix = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjacencyMatrix[i] = (int *)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
        {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Add edge to undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    graph->adjacencyMatrix[src][dest] = 1;

    // Add edge from dest to src (for undirected graph)
    graph->adjacencyMatrix[dest][src] = 1;
}

// BFS algorithm implementation
void bfs(struct Graph *graph, int startVertex, int *visited, int *path, int *pathSize)
{
    struct Queue *q = createQueue();

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(q, startVertex);

    // Add start vertex to path
    path[(*pathSize)++] = startVertex;

    while (!isQueueEmpty(q))
    {
        // Dequeue a vertex and print it
        int currentVertex = dequeue(q);

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent has not been visited, mark it visited and enqueue it
        for (int i = 0; i < graph->vertices; i++)
        {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(q, i);

                // Add to path
                path[(*pathSize)++] = i;
            }
        }
    }

    free(q);
}

// Function to display the BFS path
void displayBFSPath(int *path, int pathSize)
{
    for (int i = 0; i < pathSize; i++)
    {
        printf("%d ", path[i]);
    }
    printf("\n");
}