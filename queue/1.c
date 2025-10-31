#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Queue {
    struct Node* front;
    struct Node* rear;
};


struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}


int isEmpty(struct Queue* q) {
    return q->front == NULL;
}


void enqueue(struct Queue* q, int data) {
    struct Node* temp = newNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}


int dequeue(struct Queue* q) {
    if (isEmpty(q)) return -1;
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return data;
}


void displayQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = q->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* q = createQueue();
    int choice, value, numValues;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many values do you want to enqueue? ");
                scanf("%d", &numValues);
                for (int i = 0; i < numValues; i++) {
                    printf("Enter value %d to enqueue: ", i + 1);
                    scanf("%d", &value);
                    enqueue(q, value);
                }
                break;
            case 2:
                value = dequeue(q);
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                else
                    printf("Queue is empty!\n");
                break;
            case 3:
                printf("Queue: ");
                displayQueue(q);
                break;
            case 4:
                printf("Goodbye...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

