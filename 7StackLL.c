#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (!top) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);
    return x;
}

void display() {
    if (!top) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, x;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            x = pop();
            if (x != -1)
                printf("Popped: %d\n", x);
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