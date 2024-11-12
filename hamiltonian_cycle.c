#include <stdio.h>
#include <stdlib.h>

int n;
int **graph;
int *path;

void printCycle() {
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);
}

int isValidVertex(int k) {
    if (graph[path[k - 1]][path[k]] && !memchr(path, path[k], k * sizeof(int))) {
        return 1;
    }
    return 0;
}

void hamiltonianCycle(int k) {
    if (k == n) {
        if (graph[path[n - 1]][path[0]]) {
            printCycle();
        }
        return;
    }

    for (path[k] = 1; path[k] <= n; path[k]++) {
        if (isValidVertex(k)) {
            hamiltonianCycle(k + 1);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    graph = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        graph[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    printf("Enter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    path = (int *)malloc(n * sizeof(int));
    path[0] = 1;

    hamiltonianCycle(1);

    for (int i = 0; i <= n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(path);

    return 0;
}
