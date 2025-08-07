


#include <stdio.h>
#include <stdlib.h>


int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    int **transpose = (int **)malloc(cols * sizeof(int *));
    for(int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));
    for(int i = 0; i < cols; i++)
        transpose[i] = (int *)malloc(rows * sizeof(int));

    printf("Enter matrix elements:\n");
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            transpose[j][i] = matrix[i][j];

    printf("Transposed matrix:\n");
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }

    // Free memory
    for(int i = 0; i < rows; i++)
        free(matrix[i]);
    for(int i = 0; i < cols; i++)
        free(transpose[i]);
    free(matrix);
    free(transpose);
    return 0;
}
