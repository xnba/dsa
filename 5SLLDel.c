#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insertAtEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteFromEnd() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    if (!head->next) {
        free(head);
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteFromPosition(int position) {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    for (int i = 1; i < position && temp; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Position out of range\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display() {
    Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, position;
    while (1) {
        printf("\n1. Insert\n2. Delete from beginning\n3. Delete from end\n4. Delete from position\n5. Display\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 2:
                deleteFromBeginning();
                break;
            case 3:
                deleteFromEnd();
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}