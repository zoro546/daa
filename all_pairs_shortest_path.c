#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define INF_STR "INF"

void print_matrix(int **dist, int V, int iteration) {
    printf("\nMatrix A^%d:\n", iteration);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void all_pairs_shortest_path(int **graph, int V) {
    int **dist;
    int i, j, k;

    dist = (int **)malloc(V * sizeof(int *));
    for (i = 0; i < V; i++) {
        dist[i] = (int *)malloc(V * sizeof(int));
    }

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    print_matrix(dist, V, 0);

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        print_matrix(dist, V, k + 1);
    }

    for (i = 0; i < V; i++) {
        free(dist[i]);
    }
    free(dist);
}

int main() {
    int V;
    int **graph;
    char input[100];

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    getchar();

    printf("Enter the adjacency matrix row-wise (use 'INF' for infinity):\n");
    for (int i = 0; i < V; i++) {
        printf("Enter row %d: ", i + 1);
        fgets(input, sizeof(input), stdin);

        char *token = strtok(input, " ");
        for (int j = 0; j < V && token != NULL; j++) {
            if (strcmp(token, INF_STR) == 0 || strcmp(token, "INF\n") == 0) {
                graph[i][j] = INT_MAX;
            } else {
                graph[i][j] = atoi(token);
            }
            token = strtok(NULL, " ");
        }
    }

    all_pairs_shortest_path(graph, V);

    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
