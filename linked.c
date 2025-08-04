#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node *link;
};

// Function to print the linked list
void printList(struct node *head) {
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

// Function to free memory
void freeList(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
}

int main() {
    // Allocate memory for first node
    struct node *head = malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory allocation failed for head\n");
        return 1;
    }

    head->data = 45;
    head->link = NULL;

    // Allocate memory for second node
    struct node *current = malloc(sizeof(struct node));
    if (current == NULL) {
        printf("Memory allocation failed for current\n");
        free(head); // Free already allocated memory
        return 1;
    }

    current->data = 69;
    current->link = NULL;
    head->link = current;

    // Print the list
    printList(head);

    // Free memory to avoid leak
    freeList(head);

    
}

