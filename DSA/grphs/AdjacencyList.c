#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 5 

// structure for adjacency List node 
struct Node {
    int dest;
    struct Node *next;
};

// structure for an adjacency List 
struct AdjList{
    struct Node * head ;
};

// structure for the grapg 
struct Graph {
    int V;
    struct AdjList *array;
};

// create a new adjacency list node 
struct Node* createNode(int dest){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;

    return newNode;
}

// create a graph with V vertices 
struct Graph * createGraph(int V){
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    graph->V = V ;  // a interger V that stores the number of vertices
    graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList)); // this lines allocates memory for an array of Adjlist structues . SInce we  have v vertcies we create an array of size V

    for(int i = 0 ; i < V ; ++i){
        graph->array[i].head = NULL;
    }

    return graph;
}

// The addEdge function adds edge between two vertices in and undirected graph 
// it  creates a new node for `dest` and links it to the adjancy list pf `src`. 
// then does the reverse by adding a new nod for `src` to the adjacency list of `dest`.
// This ensures that both vertices reflect the edge , as required  in an undriected  graph 

void addEdge(struct Graph* graph, int src , int dest){
    struct Node *newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}



// Print the adjacency list representation of the graph 
void printGraph(struct Graph* graph ){
    for (int v = 0; v < graph->V; ++v){
        struct Node *temp = graph->array[v].head;
        printf("\nAdjanacny list of vertex %d\n head", v);
        while(temp){
            printf("->%d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int V = 5;
    struct Graph *graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}