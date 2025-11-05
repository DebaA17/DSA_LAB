#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueueMultiple() {
    int value, n;
    printf("How many values do you want to enqueue? ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        if (rear == MAX - 1) {
            printf("Queue is full, cannot enqueue more values.\n");
            return;
        }
        
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    int value;
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        value = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return value;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Enqueue multiple values\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueueMultiple();
                break;
            case 2:
                {
                    int value = dequeue();
                    if (value != -1) {
                        printf("Dequeued value: %d\n", value);
                    }
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
