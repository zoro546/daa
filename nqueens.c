#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *x;

int place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

void NQUEENS(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                for (int j = 1; j <= n; j++) {
                    printf("%d ", x[j]);
                }
                printf("\n");
            } else {
                NQUEENS(k + 1, n);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of queens (N): ");
    scanf("%d", &n);

    x = (int *)malloc((n + 1) * sizeof(int));

    printf("The possible solutions are:\n");
    NQUEENS(1, n);

    free(x);

    return 0;
}
