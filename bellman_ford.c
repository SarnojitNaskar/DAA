#include <stdio.h>
#include <stdlib.h>

#define INF 9999

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int V, int E, struct Edge edges[], int start) {
    int i, j, distance[V];
    for (i = 0; i < V; ++i)
        distance[i] = INF;
    distance[start] = 0;

    for (i = 1; i < V; ++i) {
        for (j = 0; j < E; ++j) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if (distance[u] != INF && distance[u] + w < distance[v])
                distance[v] = distance[u] + w;
        }
    }

    // Check for negative weight cycles
    for (i = 0; i < E; ++i) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    // Print shortest distances
    printf("Vertex\tDistance from Start\n");
    for (i = 0; i < V; ++i)
        printf("%d\t%d\n", i, distance[i]);
}

int main() {
    int V = 5; // Number of vertices
    int E = 8; // Number of edges
    struct Edge edges[] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3},
        {1, 3, 2}, {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };
    int start = 0; // Starting vertex

    bellmanFord(V, E, edges, start);

    return 0;
}

