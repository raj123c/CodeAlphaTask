#include <stdio.h>

#define MAX 10

// Function declarations
void readMatrix(int mat[MAX][MAX], int r, int c);
void printMatrix(int mat[MAX][MAX], int r, int c);
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int r, int c);
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int mat[MAX][MAX], int r, int c);

int main() {
    int a[MAX][MAX], b[MAX][MAX];
    int r1, c1, r2, c2, choice;

    printf("Select Operation:\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Transpose of Matrix\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

        case 1:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter first matrix:\n");
            readMatrix(a, r1, c1);

            printf("Enter second matrix:\n");
            readMatrix(b, r1, c1);

            addMatrix(a, b, r1, c1);
            break;

        case 2:
            printf("Enter rows and columns of first matrix: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter rows and columns of second matrix: ");
            scanf("%d %d", &r2, &c2);

            if (c1 != r2) {
                printf("Matrix multiplication not possible.\n");
                break;
            }

            printf("Enter first matrix:\n");
            readMatrix(a, r1, c1);

            printf("Enter second matrix:\n");
            readMatrix(b, r2, c2);

            multiplyMatrix(a, b, r1, c1, c2);
            break;

        case 3:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter matrix:\n");
            readMatrix(a, r1, c1);

            transposeMatrix(a, r1, c1);
            break;

        default:
            printf("Invalid choice!");
    }

    return 0;
}

// Function to read a matrix
void readMatrix(int mat[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}

// Function to print a matrix
void printMatrix(int mat[MAX][MAX], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Function for matrix addition
void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int r, int c) {
    int sum[MAX][MAX], i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            sum[i][j] = a[i][j] + b[i][j];

    printf("Resultant Matrix (Addition):\n");
    printMatrix(sum, r, c);
}

// Function for matrix multiplication
void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int c2) {
    int mul[MAX][MAX], i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            mul[i][j] = 0;
            for (k = 0; k < c1; k++)
                mul[i][j] += a[i][k] * b[k][j];
        }
    }

    printf("Resultant Matrix (Multiplication):\n");
    printMatrix(mul, r1, c2);
}

// Function for transpose
void transposeMatrix(int mat[MAX][MAX], int r, int c) {
    int trans[MAX][MAX], i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            trans[j][i] = mat[i][j];

    printf("Transpose Matrix:\n");
    printMatrix(trans, c, r);
}