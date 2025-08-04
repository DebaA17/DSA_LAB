#include <stdio.h>

int main() {
    int m, n;

    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    int matrix1[m][n], matrix2[m][n], result[m][n];

    printf("\nEnter elements of the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix1[%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    
    printf("\nEnter elements of the second matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix2[%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nMatrix 1:\n");
    for (int i = 0; i < m; i++) {
        printf("| ");
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("|\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < m; i++) {
        printf("| ");
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("|\n");
    }

    printf("\nResultant Matrix (Matrix1 + Matrix2):\n");
    for (int i = 0; i < m; i++) {
        printf("| ");
        for (int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("|\n");
    }

    return 0;
}
