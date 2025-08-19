
// double linked list



#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} NODE;


NODE *start=NULL;


void displayList() {
    NODE *temp = start;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("\n\nDoubly linked list (forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void createList() {
    int listLen;

    printf("Enter the number of Node : ");
    scanf("%d", &listLen);

    NODE *newNode,*temp;

    for (int i=0;i<listLen;i++) {
        int data;
        newNode = (NODE *)malloc(sizeof(NODE));

        printf("Enter data for node %d : ", i+1);
        scanf("%d", &data);

        newNode->prev = NULL;
        newNode->data = data;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
            temp = start;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    displayList();
}



void insertAtStart() {
    int data;
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter data for new node : ");
    scanf("%d", &data);

    temp->prev = NULL;
    temp->data = data;
    temp->next = start;
    start = temp;

    displayList();
}

void insertAtEnd() {

    NODE *beforeLast,*temp;
    temp = start;

    while (temp != NULL) {
        if (temp->next == NULL) {
            beforeLast = temp;
        }
        temp = temp->next;
    }

    int data;
    temp = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter data for new node : ");
    scanf("%d", &data);

    temp->prev = beforeLast;
    temp->data = data;
    temp->next = NULL;

    beforeLast->next = temp;

    displayList();
    
}

void insertAtPosition() {
    int count = 0, position, data;


    printf("\nEnter the position : ");
    scanf("%d", &position);
    printf("Enter the data for the new node: ");
    scanf("%d", &data);

    if (position == 1) {
        insertAtStart();
        return;
    }


    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    NODE *temp = start;
    while (count < position - 2 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    newNode->prev = temp->prev;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node with data %d inserted at position %d\n", data, position);
}

void deleteAtStart() {

    NODE *temp = start;
    start = start->next;
    start->prev = NULL;
    free(temp);

    displayList();
}

void deleteAtEnd() {
    NODE *beforeLast,*temp;
    temp = start;

    while (temp->next != NULL) {
        beforeLast = temp;
        temp = temp->next;
    }
    

    beforeLast->next = NULL;
    free(temp);

    displayList();
    
}

void deleteAtPosition() {
    int position;
    printf("\nEnter the position to delete: ");
    scanf("%d", &position);


    if (position <= 0) {
        printf("Invalid position!\n");
        return;
    }


    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }


    if (position == 1) {
       deleteAtStart();
        return;
    }


    NODE *temp = start;
    NODE *prev = NULL;
    int count = 0;

    while (count < position - 1 && temp != NULL) {
        prev = temp;
        temp = temp->next;
        count++;
    }


    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    
    prev->next = temp->next;
    free(temp);

    displayList();
}

int main() {
    int choice = 9;

    

    while (1) {
        printf("\n");
        printf("1) Create the list \n");
        printf("2) Insert at the beginning of the list\n");
        printf("3) Insert at the end of the list \n");
        printf("4) Insert at any position \n");
        printf("5) Delete at the beginning of the list\n");
        printf("6) Delete at the end of the list \n");
        printf("7) Delete at any position \n");
        printf("8) Display List \n");
        printf("9) Exit \n");
        printf("\n");
        printf("select option : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            createList();
            continue;
            break;
        
        case 2:
            insertAtStart();
            continue;
            break;

        case 3:
            insertAtEnd();
            continue;
            break;

        case 4:
            insertAtPosition();
            continue;
            break;
        
        case 5:
            deleteAtStart();
            continue;
            break;
        
        case 6:
            deleteAtEnd();
            continue;
            break;

        case 7:
            deleteAtPosition();
            continue;
            break;

        case 8:
            displayList();
            continue;
            break;

        case 9:
            return 0;
            break;
        
        default:
            break;
        }
    }


    return 0;
}