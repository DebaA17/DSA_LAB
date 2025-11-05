#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

void enqueueMultiple(struct Queue *q) {
    int n, value;
    printf("How many values do you want to enqueue? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);

        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed\n");
            return;
        }
        newNode->data = value;
        newNode->next = NULL;

        if (q->rear == NULL) {
            q->front = q->rear = newNode;
        } else {
            q->rear->next = newNode;
            q->rear = newNode;
        }
    }
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = q->front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    initQueue(&q);
    int choice;

    while (1) {
        printf("1. Enqueue multiple values\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueueMultiple(&q);
                break;
            case 2:
                {
                    int value = dequeue(&q);
                    if (value != -1) {
                        printf("Dequeued value: %d\n", value);
                    }
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
