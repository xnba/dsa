#include <stdio.h>

#define MAX 100  // Maximum size of the tree array

void insert(int tree[], int data, int i) {
    if (i < MAX) {
        if (tree[i] == -1) {
            tree[i] = data;
        } else {
            printf("Position already filled. Try another position.\n");
        }
    } else {
        printf("Index out of bound.\n");
    }
}

void displayTree(int tree[], int n) {
    printf("Tree elements:\n");
    for (int i = 0; i < n; i++) {
        if (tree[i] != -1) {
            printf("%d ", tree[i]);
        } else {
            printf("_ ");  // Placeholder for empty positions
        }
    }
    printf("\n");
}

int main() {
    int tree[MAX];
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;  // Initialize tree with -1 (indicating empty nodes)
    }

    int n, data, pos;

    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        printf("Enter the position to insert the node (starting from 0): ");
        scanf("%d", &pos);
        insert(tree, data, pos);
    }

    displayTree(tree, MAX);

    return 0;
}