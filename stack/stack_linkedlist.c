#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;  // Top of stack

//push
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed! Stack Overflow.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;  
    top = newNode;        // update top
    printf("%d pushed to stack.\n", value);
}

//pop
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! No element to pop.\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;   // move top to next node
    free(temp);        // free memory
}

//display the stack 
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//main
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu (Linked List) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
