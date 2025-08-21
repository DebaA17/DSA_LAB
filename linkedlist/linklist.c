#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in the linked list
struct node {
    int info;
    struct node *next;
};

// Global pointer to the start of the linked list
struct node *start = NULL;
// Function to create a linked list with n nodes
void createlist() {
    if (start != NULL) {
        printf("List already exists! Please delete it first or use insert operations.\n");
        return;
    }
    
    int n, data;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid number of elements!\n");
        return;
    }
    
    struct node *newnode, *temp;
    
    // Create first node
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    newnode->info = data;
    newnode->next = NULL;
    start = newnode;
    temp = start;
    
    // Create remaining nodes
    for (int i = 2; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newnode->info = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
    printf("List created successfully with %d nodes.\n", n);
}
// Function to display the linked list
void display() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct node *temp = start;
    printf("List contents: ");
    while (temp != NULL) {
        printf("%d", temp->info);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}
// Function to insert a node at the beginning of the list
void insfirst() {
    struct node *newnode;
    int data;
    
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter the data for new node: ");
    scanf("%d", &data);
    newnode->info = data;
    newnode->next = start;
    start = newnode;
    printf("Node inserted at the beginning successfully.\n");
}
// Function to insert a node at the end of the list
void inslast() {
    struct node *newnode, *temp;
    int data;
    
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter the data for new node: ");
    scanf("%d", &data);
    newnode->info = data;
    newnode->next = NULL;
    
    if (start == NULL) {
        start = newnode;
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Node inserted at the end successfully.\n");
}
// Function to insert a node at a specific position
void insmid() {
    if (start == NULL) {
        printf("List is empty! Please create the list first.\n");
        return;
    }
    
    struct node *newnode, *temp;
    int data, pos, count = 0;
    
    // Count nodes
    temp = start;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    printf("Enter the position to insert (1 to %d): ", count + 1);
    scanf("%d", &pos);
    
    if (pos < 1 || pos > count + 1) {
        printf("Invalid position! Position should be between 1 and %d.\n", count + 1);
        return;
    }
    
    if (pos == 1) {
        insfirst();
        return;
    }
    
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter the data for new node: ");
    scanf("%d", &data);
    newnode->info = data;
    
    temp = start;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Node inserted at position %d successfully.\n", pos);
}
// Function to delete the first node
void deletefirst() {
    if (start == NULL) {
        printf("The list is empty! Nothing to delete.\n");
        return;
    }
    
    struct node *temp = start;
    start = start->next;
    printf("Deleted node with data: %d\n", temp->info);
    free(temp);
}
// Function to delete the last node
void deletend() {
    if (start == NULL) {
        printf("The list is empty! Nothing to delete.\n");
        return;
    }
    
    struct node *temp = start;
    
    // If only one node exists
    if (temp->next == NULL) {
        printf("Deleted node with data: %d\n", temp->info);
        free(temp);
        start = NULL;
        return;
    }
    
    // Find the second last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    printf("Deleted node with data: %d\n", temp->next->info);
    free(temp->next);
    temp->next = NULL;
}
// Function to delete a node at a specific position
void deleteany() {
    if (start == NULL) {
        printf("The list is empty! Nothing to delete.\n");
        return;
    }
    
    struct node *temp = start;
    int count = 0, pos;
    
    // Count nodes
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    printf("Enter position to delete (1 to %d): ", count);
    scanf("%d", &pos);
    
    if (pos < 1 || pos > count) {
        printf("Invalid position! Position should be between 1 and %d.\n", count);
        return;
    }
    
    if (pos == 1) {
        deletefirst();
        return;
    }
    
    temp = start;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    struct node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted node with data: %d\n", nodeToDelete->info);
    free(nodeToDelete);
}
// Function to count the number of nodes in the list
int countNodes() {
    int count = 0;
    struct node *temp = start;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to search for a value in the list
void searchValue() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    int value, position = 1;
    printf("Enter value to search: ");
    scanf("%d", &value);
    
    struct node *temp = start;
    while (temp != NULL) {
        if (temp->info == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value %d not found in the list.\n", value);
}

// Function to free all memory and delete the entire list
void deleteList() {
    if (start == NULL) {
        printf("List is already empty!\n");
        return;
    }
    
    struct node *temp;
    int deletedCount = 0;
    while (start != NULL) {
        temp = start;
        start = start->next;
        free(temp);
        deletedCount++;
    }
    printf("Entire list deleted successfully! %d nodes freed.\n", deletedCount);
}

// Main function with enhanced menu
int main() {
    int choice;
    
    printf("========================================\n");
    printf("    SINGLY LINKED LIST OPERATIONS\n");
    printf("========================================\n");
    
    while (1) {
        printf("\n=================== MENU ===================\n");
        printf("1.  Create the list\n");
        printf("2.  Insert at beginning\n");
        printf("3.  Insert at end\n");
        printf("4.  Insert at specific position\n");
        printf("5.  Delete from beginning\n");
        printf("6.  Delete from end\n");
        printf("7.  Delete from specific position\n");
        printf("8.  Display list\n");
        printf("9.  Count nodes\n");
        printf("10. Search value\n");
        printf("11. Delete entire list\n");
        printf("12. Exit\n");
        printf("============================================\n");
        
        printf("Enter your choice (1-12): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createlist();
                break;
            case 2:
                insfirst();
                break;
            case 3:
                inslast();
                break;
            case 4:
                insmid();
                break;
            case 5:
                deletefirst();
                break;
            case 6:
                deletend();
                break;
            case 7:
                deleteany();
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Total number of nodes: %d\n", countNodes());
                break;
            case 10:
                searchValue();
                break;
            case 11:
                deleteList();
                break;
            case 12:
                printf("Cleaning up memory before exit...\n");
                deleteList();
                printf("Thank you for using the program!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 12.\n");
        }
    }
    return 0;
}
