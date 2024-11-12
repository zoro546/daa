
#include <stdio.h>

void minmax(int A[], int i, int j, int *max, int *min) {
    int mid, max1, min1;

    if (i == j) {
        *max = *min = A[i];
    }
    else if (j == i + 1) {
        if (A[i] < A[j]) {
            *max = A[j];
            *min = A[i];
        } else {
            *max = A[i];
            *min = A[j];
        }
    } else {
        mid = (i + j) / 2;
        minmax(A, i, mid, max, min);
        minmax(A, mid + 1, j, &max1, &min1);

        if (*max < max1) {
            *max = max1;
        }
        if (*min > min1) {
            *min = min1;
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int max, min;
    minmax(A, 0, n - 1, &max, &min);

    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}
