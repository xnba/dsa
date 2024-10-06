#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    if (!rear) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if (!front) {
        printf("Queue is empty\n");
        return -1;
    }
    int x = front->data;
    Node* temp = front;
    front = front->next;
    if (!front) rear = NULL;
    free(temp);
    return x;
}

void display() {
    if (!front) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, x;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            x = dequeue();
            if (x != -1)
                printf("Dequeued: %d\n", x);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}