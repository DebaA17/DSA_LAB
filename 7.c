#include <stdio.h>

int main() {
    int a[10][10], b[10][10], mul[10][10];
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if multiplication is possible
    if(c1 != r2) {
        printf("Matrix multiplication not possible.\n");
        return 0;
    }

    // Input first matrix
    printf("Enter elements of first matrix:\n");
    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    // Input second matrix
    printf("Enter elements of second matrix:\n");
    for(int i = 0; i < r2; i++)
        for(int j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    // Multiply matrices
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            mul[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print result
    printf("Product of the matrices:\n");
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++)
            printf("%d ", mul[i][j]);
        printf("\n");
    }

    return 0;
}

