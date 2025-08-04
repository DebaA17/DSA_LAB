#include <stdio.h>

int main() {
    int a[10][10], trans[10][10], rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input original matrix
    printf("Enter elements of the matrix:\n");
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    // Transpose the matrix
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            trans[j][i] = a[i][j];

    // Print transpose
    printf("Transpose of the matrix:\n");
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++)
            printf("%d ", trans[i][j]);
        printf("\n");
    }

    return 0;
}

