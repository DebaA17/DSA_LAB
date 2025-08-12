// STACK IN C - Simple Explanation and Code
// Stack: LIFO (Last In First Out) - like a stack of plates
// Operations: PUSH (add), POP (remove), PEEK (see top), DISPLAY

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum stack size

// Stack structure
struct Stack {
    int arr[MAX];  // Array to store elements
    int top;       // Index of top element (-1 means empty)
};

struct Stack stack;  // Global stack variable

// Initialize stack
void init_stack() {
    stack.top = -1;  // Empty stack
    printf("Stack initialized (size: %d)\n", MAX);
}

// Check if stack is full
int is_full() {
    return stack.top == MAX - 1;  // top = 4 means full (for MAX=5)
}

// Check if stack is empty
int is_empty() {
    return stack.top == -1;  // top = -1 means empty
}

// PUSH: Add element to top of stack
void push() {
    int num;
    
    if (is_full()) {
        printf("Stack OVERFLOW! Cannot add more elements\n");
        return;
    }
    
    printf("Enter number to push: ");
    scanf("%d", &num);
    
    stack.top++;                    // Move top pointer up
    stack.arr[stack.top] = num;     // Add element at top
    
    printf("Pushed %d to stack\n", num);
}

// POP: Remove and return top element
void pop() {
    if (is_empty()) {
        printf("Stack UNDERFLOW! No elements to remove\n");
        return;
    }
    
    int popped = stack.arr[stack.top];  // Get top element
    stack.top--;                        // Move top pointer down
    
    printf("Popped %d from stack\n", popped);
}

// PEEK: See top element without removing
void peek() {
    if (is_empty()) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Top element: %d\n", stack.arr[stack.top]);
}

// DISPLAY: Show all stack elements
void display() {
    if (is_empty()) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack (top to bottom): ");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d ", stack.arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    
    init_stack();
    
    printf("\n=== STACK OPERATIONS ===\n");
    
    while (1) {
        printf("\n1. PUSH (add element)\n");
        printf("2. POP (remove element)\n");
        printf("3. PEEK (see top element)\n");
        printf("4. DISPLAY (show stack)\n");
        printf("5. EXIT\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}

/*
STACK EXPLANATION:
==================

What is Stack?
- Like a stack of plates: add on top, remove from top
- LIFO: Last In, First Out
- Example: 
  Push 10 → [10]
  Push 20 → [20, 10]  (20 is on top)
  Pop     → [10]      (20 removed)

Key Operations:
1. PUSH: Add element to top
2. POP: Remove element from top  
3. PEEK: Look at top element
4. DISPLAY: Show all elements

Stack States:
- EMPTY: top = -1
- FULL: top = MAX-1
- OVERFLOW: trying to push when full
- UNDERFLOW: trying to pop when empty

Example Run:
Choice: 1, Enter: 10 → Stack: [10]
Choice: 1, Enter: 20 → Stack: [20, 10]
Choice: 3 → Top: 20
Choice: 2 → Popped: 20, Stack: [10]
*/
