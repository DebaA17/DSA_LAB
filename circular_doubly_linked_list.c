#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }
    
    struct Node* last = (*head)->prev;
    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
}

void deleteNode(struct Node** head, int data) {
    if (*head == NULL) return;
    
    struct Node* temp = *head;
    
    if (temp->next == *head && temp->data == data) {
        free(temp);
        *head = NULL;
        return;
    }
    
    do {
        if (temp->data == data) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            
            if (temp == *head) {
                *head = temp->next;
            }
            
            free(temp);
            return;
        }
        temp = temp->next;
    } while (temp != *head);
}

void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Forward: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head->prev;
    printf("Backward: ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("\n");
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
    
    displayForward(head);
    displayBackward(head);
    
    deleteNode(&head, 20);
    printf("After deleting 20:\n");
    displayForward(head);
    
    freeList(head);
    return 0;
}
