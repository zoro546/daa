
#include <stdio.h>

void greedyKnapsack(int n, float weights[], float profits[], float capacity) {
    float x[n];
    float totalProfit = 0;
    int i;
    float currentCapacity = capacity;

    for (i = 0; i < n; i++) {
        x[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (weights[i] > currentCapacity) {
            break;
        }
        x[i] = 1;
        currentCapacity -= weights[i];
        totalProfit += profits[i];
    }

    if (i < n) {
        x[i] = currentCapacity / weights[i];
        totalProfit += x[i] * profits[i];
    }

    printf("Solution vector: ");
    for (i = 0; i < n; i++) {
        printf("%f ", x[i]);
    }
    printf("\nTotal profit: %f\n", totalProfit);
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    float weights[n], profits[n];

    printf("Enter the weights of the objects: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &weights[i]);
    }

    printf("Enter the profits of the objects: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &profits[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    greedyKnapsack(n, weights, profits, capacity);

    return 0;
}
