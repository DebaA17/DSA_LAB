#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

int main(){
	struct node *head = malloc(sizeof(struct node));
	struct node *second = malloc(sizeof(struct node));


	head->data = 45;
	head->link = second;

	second->data=69;
	second->link = NULL;


	struct node *temp = head;
	while (temp) {
		printf("%d -> ",temp->data);
		temp = temp->link;
	}
	printf("NULL\n");

}
