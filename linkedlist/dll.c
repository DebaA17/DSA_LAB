#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *start = NULL, *last = NULL;

void create(int n) {
    for (int i = 0; i < n; i++) {
        struct node *new = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &new->data);
        new->next = NULL;
        new->prev = last;
        if (!start) start = new;
        else last->next = new;
        last = new;
    }
}

void display() {
    for (struct node *t = start; t; t = t->next)
        printf("%d ", t->data);
    printf("\n");
}

void insert_pos(int data, int pos) {
    struct node *new = malloc(sizeof(struct node)), *t = start;
    new->data = data;

    if (pos <= 1 || !start) {
        new->prev = NULL;
        new->next = start;
        if (start) start->prev = new;
        else last = new;
        start = new;
        return;
    }

    for (int i = 1; i < pos - 1 && t->next; i++) t = t->next;

    new->next = t->next;
    new->prev = t;
    if (t->next) t->next->prev = new;
    else last = new;
    t->next = new;
}

void delete_pos(int pos) {
    if (!start) return;
    struct node *t = start;

    if (pos == 1) {
        start = start->next;
        if (start) start->prev = NULL;
        else last = NULL;
        free(t);
        return;
    }

    for (int i = 1; i < pos && t; i++) t = t->next;
    if (!t) return;

    if (t->prev) t->prev->next = t->next;
    if (t->next) t->next->prev = t->prev;
    if (t == last) last = t->prev;
    free(t);
}

int main() {
    int choice, n, data, pos;

    while (1) {
        printf("\n1.Create  2.Display  3.Insert  4.Delete  5.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                create(n); break;
            case 2:
                display(); break;
            case 3:
                printf("Data & Position: ");
                scanf("%d%d", &data, &pos);
                insert_pos(data, pos); break;
            case 4:
                printf("Position to delete: ");
                scanf("%d", &pos);
                delete_pos(pos); break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

