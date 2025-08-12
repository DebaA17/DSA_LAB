// SIMPLE DOUBLY LINKED LIST - Only 2 Insert Operations
// Each node has: data, prev pointer, next pointer

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;           // stores the number
    struct Node *prev;  // points to previous node
    struct Node *next;  // points to next node
};

struct Node* head = NULL;  // first node of list

// INSERT AT BEGINNING
void insert_beginning() {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    
    // Step 1: Create new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = num;
    new_node->prev = NULL;  // no previous node (it's first)
    new_node->next = head;  // point to current first node
    
    // Step 2: Update old first node
    if (head != NULL)
        head->prev = new_node;  // old first node points back to new node
    
    // Step 3: Make new node the first
    head = new_node;
    
    printf("Added %d at beginning\n", num);
}

// INSERT AT END
void insert_end() {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    
    // Step 1: Create new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = num;
    new_node->next = NULL;  // no next node (it's last)
    
    // Step 2: If list is empty, make it first node
    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        printf("Added %d (first node)\n", num);
        return;
    }
    
    // Step 3: Find last node
    struct Node* last = head;
    while (last->next != NULL)
        last = last->next;
    
    // Step 4: Connect new node at end
    last->next = new_node;
    new_node->prev = last;
    
    printf("Added %d at end\n", num);
}

// DISPLAY LIST
void show_list() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    
    printf("=== SIMPLE DOUBLY LINKED LIST ===\n");
    
    while (1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Show list\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            insert_beginning();
        }
        else if (choice == 2) {
            insert_end();
        }
        else if (choice == 3) {
            show_list();
        }
        else if (choice == 4) {
            printf("Bye!\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    
    return 0;
}