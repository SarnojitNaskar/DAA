#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices
#define INF INT_MAX // Infinity

void printMatrix(int matrix[][V]);

void floydWarshall(int graph[][V]) {
    int dist[V][V];
    int i, j, k;

    // Initialize the distance matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Update the distance matrix
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest paths
    printMatrix(dist);
}

void printMatrix(int matrix[][V]) {
	int i, j;
    printf("Shortest path matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (matrix[i][j] == INF) {
                printf("INF ");
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    floydWarshall(graph);
    return 0;
}

