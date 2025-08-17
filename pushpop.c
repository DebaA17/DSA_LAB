#include <stdio.h>

#define MAX 5

int stack_arr[MAX];
int top = -1;

void push();
void pop();
void display();

int main() {
    int choice;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program... Tata!\n");
                return 0;
            default:
                printf("Invalid choice! Try again, bro.\n");
        }
    }

    return 0;
}

void push() {
    int data;
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
        printf("Please contact email: contact@debasisbiswas.me\n");
        return;
    }

    printf("Enter the data to push: ");
    scanf("%d", &data);
    top = top + 1;
    stack_arr[top] = data;
    printf("%d pushed onto stack\n", data);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }

    printf("%d popped from stack.\n", stack_arr[top]);
    top = top - 1;
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

