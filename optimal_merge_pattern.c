
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int weight;
    struct Node *left, *right;
} Node;

Node* getNode(int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->weight = weight;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findLeast(Node** list, int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (list[i] && list[i]->weight < list[minIndex]->weight) {
            minIndex = i;
        }
    }
    return minIndex;
}

Node* extractLeast(Node** list, int* n) {
    int minIndex = findLeast(list, *n);
    Node* leastNode = list[minIndex];
    for (int i = minIndex; i < *n - 1; i++) {
        list[i] = list[i + 1];
    }
    (*n)--;
    return leastNode;
}

void insert(Node** list, Node* node, int* n) {
    list[*n] = node;
    (*n)++;
}

int calculateMergeCost(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->weight + calculateMergeCost(root->left) + calculateMergeCost(root->right);
}

int main() {
    int n;
    printf("Enter the number of files: ");
    scanf("%d", &n);

    Node* list[n];
    printf("Enter the weights of the files: ");
    for (int i = 0; i < n; i++) {
        int weight;
        scanf("%d", &weight);
        list[i] = getNode(weight);
    }

    int listSize = n;
    while (listSize > 1) {
        Node* node = getNode(0);
        node->left = extractLeast(list, &listSize);
        node->right = extractLeast(list, &listSize);
        node->weight = node->left->weight + node->right->weight;
        insert(list, node, &listSize);
    }

    Node* root = list[0];
    int totalMergeCost = calculateMergeCost(root) - root->weight;
    printf("Total merge cost: %d\n", totalMergeCost);

    return 0;
}
