#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) return;
    
    struct Node* temp = *head;
    struct Node* prev = NULL;
    
    if (temp->data == data && temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }
    
    if (temp->data == data) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
        return;
    }
    
    while (temp->next != *head && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp->data != data) return;
    
    prev->next = temp->next;
    free(temp);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to %d)\n", head->data);
}

void freeList(struct Node* head) {
    if (head == NULL) return;
    
    struct Node* temp = head;
    struct Node* next;
    
    do {
        next = temp->next;
        free(temp);
        temp = next;
    } while (temp != head);
}

int main() {
    struct Node* head = NULL;
    
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    
    display(head);
    
    deleteNode(&head, 20);
    printf("After deleting 20:\n");
    display(head);
    
    freeList(head);
    return 0;
}
