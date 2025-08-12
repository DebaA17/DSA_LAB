#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* head = NULL;

void insert_beginning() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;
    
    if (head != NULL)
        head->prev = new_node;
    head = new_node;
    printf("Inserted %d at beginning\n", data);
}

void insert_end() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }
    printf("Inserted %d at end\n", data);
}

void display_forward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display_backward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void delete_node() {
    int data;
    printf("Enter data to delete: ");
    scanf("%d", &data);
    
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Data %d not found\n", data);
        return;
    }
    
    if (temp == head) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    } else {
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }
    
    free(temp);
    printf("Deleted %d\n", data);
}

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Display forward\n");
        printf("4. Display backward\n");
        printf("5. Delete node\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insert_beginning();
                break;
            case 2:
                insert_end();
                break;
            case 3:
                display_forward();
                break;
            case 4:
                display_backward();
                break;
            case 5:
                delete_node();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}