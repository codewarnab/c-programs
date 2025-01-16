#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100 

struct Queue {
    int items[MAX];
    int front; 
    int rear ;
}; 

void initQueue(struct Queue *q){
    q->front = -1 ; 
    q->rear = -1 ; 
}

int isEmpty(struct Queue * q ){
    return (q->front == -1);
}

void enqueue(struct Queue *q , int value ){
    if (q->rear == MAX -1 ){
        printf("Queue os full \n");
    }
    else {
        if (q->front==-1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}


int dequeue(struct Queue *q ){
    int item; 
    if(isEmpty(q)){
        printf("Queue is empty \n");
        return -1; 
    }
    else {
        item = q->items[q->front];
        q->front++; 
        if(q->front > q->rear){
            q->front = q->rear = -1 ; 
        }
        return item; 
    }
}


void bfs(int graph[MAX][MAX],int visited[MAX],int start , int n ){
    struct Queue q ;
    initQueue(&q);

    // start by marking the start node as visited and enqueuing it
    visited[start] = 1;
    enqueue(&q, start);

    printf("BFS traversal starting from node %d: \n ", start);

    while (!isEmpty(&q))
    {
        int current = dequeue(&q);
        printf("%d", current); 

        //visit all the neighbours of rhe current node

        for (int i = 0; i < n; i ++ ){

            // not visisted and their is a edge between current node and node i 
            if(graph[current][i]==1 && !visited[i]){
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}


int main(){
    int n , e , start ;
    printf("Enter the number vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX] = {0}; // adjacency matrix
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (u v) where u and v are node indices(0-based):\n");
    for (int i = 0; i < e ; i++){
        int u , v ;
        scanf("%d %d", &u, &v); 
        graph[u][v] = 1 ;
        graph[v][u] = 1; 

    }

    int visited[MAX] = {0};

    printf("Enter the starting node for BFS: ");
    scanf("%d", &start);

    bfs(graph, visited, start, n);

    return  0 ; 

}