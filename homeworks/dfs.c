#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph structure
struct Graph
{
    int vertices;
    int **adjacencyMatrix;
};

// Function prototypes
struct Graph *createGraph(int vertices);
void addEdge(struct Graph *graph, int src, int dest);
void dfs(struct Graph *graph, int startVertex, int *visited, int *path, int *pathSize);
void dfsUtil(struct Graph *graph, int vertex, int *visited, int *path, int *pathSize);
void displayDFSPath(int *path, int pathSize);

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

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    // Initialize visited array and path array
    int visited[MAX_VERTICES] = {0};
    int path[MAX_VERTICES];
    int pathSize = 0;

    // Perform DFS
    dfs(graph, startVertex, visited, path, &pathSize);

    // Display DFS path
    printf("\nDFS Path: ");
    displayDFSPath(path, pathSize);

    // Free allocated memory
    for (i = 0; i < vertices; i++)
    {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);

    return 0;
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

// DFS algorithm wrapper function
void dfs(struct Graph *graph, int startVertex, int *visited, int *path, int *pathSize)
{
    // Call the recursive DFS utility function
    dfsUtil(graph, startVertex, visited, path, pathSize);
}

// DFS algorithm implementation using recursion
void dfsUtil(struct Graph *graph, int vertex, int *visited, int *path, int *pathSize)
{
    // Mark the current vertex as visited
    visited[vertex] = 1;

    // Add current vertex to path
    path[(*pathSize)++] = vertex;

    // Recur for all adjacent vertices that haven't been visited
    for (int i = 0; i < graph->vertices; i++)
    {
        if (graph->adjacencyMatrix[vertex][i] == 1 && !visited[i])
        {
            dfsUtil(graph, i, visited, path, pathSize);
        }
    }
}

// Function to display the DFS path
void displayDFSPath(int *path, int pathSize)
{
    for (int i = 0; i < pathSize; i++)
    {
        printf("%d ", path[i]);
    }
    printf("\n");
}