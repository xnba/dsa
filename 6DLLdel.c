#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

void insertAtEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFromBeginning() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head) head->prev = NULL;
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
    while (temp->next) temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
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
    for (int i = 1; i < position && temp; i++) temp = temp->next;
    if (!temp) {
        printf("Position out of range\n");
        return;
    }
    if (temp->next) temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
}

void display() {
    Node* temp = head;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    
    printf("Original list: ");
    display();
    
    deleteFromBeginning();
    printf("After deleting from beginning: ");
    display();
    
    deleteFromEnd();
    printf("After deleting from end: ");
    display();
    
    deleteFromPosition(2);
    printf("After deleting from position 2: ");
    display();
    
    return 0;
}