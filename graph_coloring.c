#include <stdio.h>
#include <stdlib.h>

int n, m;
int **graph;
int *colors;

void nextValue(int k) {
    do {
        colors[k] = (colors[k] + 1) % (m + 1);

        if (colors[k] == 0) return;

        int conflict = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[k][j] && colors[k] == colors[j]) {
                conflict = 1;
                break;
            }
        }
        if (!conflict) return;
    } while (1);
}

void m_coloring(int k) {
    while (1) {
        nextValue(k);

        if (colors[k] == 0) return;

        if (k == n) {
            printf("Solution: ");
            for (int i = 1; i <= n; i++) {
                printf("%d ", colors[i]);
            }
            printf("\n");
        } else {
            m_coloring(k + 1);
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    graph = (int **)malloc((n + 1) * sizeof(int *));
    colors = (int *)malloc((n + 1) * sizeof(int));

    printf("Enter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        graph[i] = (int *)malloc((n + 1) * sizeof(int));
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    if (m < 3) {
        printf("Not possible to color the graph with less than 3 colors.\n");
        goto cleanup;
    }

    for (int i = 1; i <= n; i++) {
        colors[i] = 0;
    }

    m_coloring(1);

cleanup:
    for (int i = 1; i <= n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(colors);

    return 0;
}
