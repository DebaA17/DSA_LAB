#include <stdio.h>

int main() {
    int a[10][10], b[10][10], sum[10][10];
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input first matrix
    printf("Enter elements of first matrix:\n");
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    // Input second matrix
    printf("Enter elements of second matrix:\n");
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &b[i][j]);

    // Add the matrices
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            sum[i][j] = a[i][j] + b[i][j];

    // Display result
    printf("Sum of the two matrices:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }

    return 0;
}

