#include <stdio.h>

void findSubsets(int arr[], int n, int target, int index, int currentSum, int subset[], int subsetSize) {
    if (currentSum == target) {
        printf("{ ");
        for (int i = 0; i < subsetSize; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }

    if (currentSum > target || index >= n) {
        return;
    }

    subset[subsetSize] = arr[index];
    findSubsets(arr, n, target, index + 1, currentSum + arr[index], subset, subsetSize + 1);

    findSubsets(arr, n, target, index + 1, currentSum, subset, subsetSize);
}

int main() {
    int n, target;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d are:\n", target);
    int subset[n];

    findSubsets(arr, n, target, 0, 0, subset, 0);

    return 0;
}
