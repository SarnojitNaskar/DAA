#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 100

void floydWarshall(int V, int graph[][MAX_VERTICES]);
void printSolution(int V, int dist[][MAX_VERTICES]);
void addEdge(int graph[][MAX_VERTICES], int src, int dest, int weight, int directed);

int main()
{
    int V, E, ch, src, dest, weight, i, j, graph[MAX_VERTICES][MAX_VERTICES];
    printf("PRESS 1: Directed\nPRESS 0: Un-directed\nEnter choice: ");
    scanf("%d",&ch);
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INT_MAX;
        }
    }

    printf("Enter the edges (format: source destination weight) (node value starts from 1):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src - 1, dest - 1, weight, ch != 0); // If ch is not 0, it's directed
    }

    // Print the initial weight matrix
    printf("\nInitial Weight Matrix:\n");
    printSolution(V, graph);

    floydWarshall(V, graph);

    return 0;
}

void addEdge(int graph[][MAX_VERTICES], int src, int dest, int weight, int directed)
{
    graph[src][dest] = weight;
    if (!directed)
        graph[dest][src] = weight;
}

void floydWarshall(int V, int graph[][MAX_VERTICES])
{
    int dist[MAX_VERTICES][MAX_VERTICES], i, j, k;

    // Initialize the solution matrix same as input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printf("\nShortest Distance Matrix:\n");
    printSolution(V, dist);
}

void printSolution(int V, int dist[][MAX_VERTICES])
{
    int i, j;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INT_MAX)
                printf("%5c", 236);
            else
                printf("%5d", dist[i][j]);
        }
        printf("\n");
    }
}
