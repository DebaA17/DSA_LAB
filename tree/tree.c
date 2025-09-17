#include <stdio.h>
#include <stdlib.h>

// Define a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build tree using user input
struct Node* buildTree() {
    int value;
    printf("Enter value (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1) {
        return NULL; // no node
    }

    struct Node* newNode = createNode(value);

    printf("Enter left child of %d:\n", value);
    newNode->left = buildTree();

    printf("Enter right child of %d:\n", value);
    newNode->right = buildTree();

    return newNode;
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    printf("Build your tree:\n");
    root = buildTree();

    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}

