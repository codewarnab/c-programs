#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int graph[MAX][MAX];
int color[MAX];
int n, m; // n = number of vertices, m = number of colors

// Check if it's safe to color vertex v with color c
bool isSafe(int v, int c)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && color[i] == c)
            return false;
    }
    return true;
}

// Recursive function to color the graph
bool nextcolor(int v)
{
    if (v == n)
        return true; // all vertices colored

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, c))
        {
            color[v] = c;

            if (nextcolor(v + 1))
                return true;
            /* BACKTRACKING PROCESS:
             * When we reach this line, it means nextcolor(v + 1) returned false
             * This indicates no valid coloring was found for remaining vertices
             *
             * What happens during backtracking:
             * 1. Current state: vertex v has color c assigned, but it leads to dead end
             * 2. Backtrack step: color[v] = 0 removes the color assignment from vertex v
             * 3. Loop continuation: algorithm tries next color (c + 1) for same vertex v
             * 4. Two outcomes:
             *    - If another color works: assigns new color and tries nextcolor(v + 1) again
             *    - If no more colors work: for loop completes and function returns false
             *
             * Example: If vertex 2 was colored with color 1 but led to dead end:
             * Before backtrack: color[2] = 1
             * After backtrack:  color[2] = 0
             * Next attempt:     Try color[2] = 2 (if available)
             *
             * Chain reaction: If all colors fail for vertex v, function returns false
             * to previous recursive call, causing backtracking to cascade up the call
             * stack until a vertex with untried color options is found.
             */
            color[v] = 0; // backtrack
        }
    }
    return false; // no color leads to solution
}

// Function to display assigned colors
void displaycolor()
{
    for (int i = 0; i < n; i++)
    {
        printf("Vertex %d → Color %d\n", i, color[i]);
    }
}

int main()
{
    int edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v) using 0-based indexing:\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // because it's undirected
    }

    // Initialize colors
    for (int i = 0; i < n; i++)
        color[i] = 0;

    if (nextcolor(0))
    {
        printf("\nColoring possible with %d colors:\n", m);
        displaycolor();
    }
    else
    {
        printf("\nColoring not possible with %d colors.\n", m);
    }

    return 0;
}
