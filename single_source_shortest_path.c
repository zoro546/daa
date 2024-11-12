#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, weight;
};

void printIteration(int dist[], int V, int iteration) {
    printf("Iteration %d:\n", iteration);
    printf("Vertex  Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d\tINF\n", i);
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
    printf("\n");
}

void BellmanFord(int V, int E, struct Edge edges[], int src) {
    int dist[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
        printIteration(dist, V, i);
    }

    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains a negative weight cycle\n");
            return;
        }
    }

    printf("\nFinal Distances:\n");
    printIteration(dist, V, V);
}

int main() {
    int V, E, src;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    for (int i = 0; i < E; i++) {
        printf("Enter edge %d (u v weight): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    BellmanFord(V, E, edges, src);

    return 0;
}
