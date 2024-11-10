// An Adjacency matrix uses a @D array to store informattion about connections between vertices its simple but not space-efficient for sparse graphs 

#include<stdio.h>

#define V 5 // Number of vertices 


void printMatrix(int graph[V][V]){
    for (int i = 0 ; i < V ; i++){
        for (int j = 0; j < V; j++){
            printf("%d", graph[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int graph[V][V] = {0};

    graph[0][1] = 1 ; 
    graph[1][0] = 1 ;

    graph[1][2] = 1;
    graph[2][1] = 1;

    graph[2][3] = 1;
    graph[3][2] = 1;

    graph[3][4] = 1;
    graph[4][3] = 1;

    graph[4][0] = 1;
    graph[0][4] = 1;

    printf("Adjacency Matrix:\n");
    printMatrix(graph);

    return 0;
}


// Explanation 
// .. the matrix graph[i][j] is 1 if theres an edge between vertices i and j otherwise its 0 
// in directed graphs , only graph[i][j] will be set to 1 for directed edge from i to j 
