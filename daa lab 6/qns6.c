#include <stdio.h>

int main() {
    int n;

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    int A[10][10], B[10][10], C[10][10];

    printf("Enter Matrix A:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    // (i) Matrix Addition
    printf("\nMatrix Addition:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // (ii) Matrix Multiplication
    printf("\nMatrix Multiplication:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = 0;

            for(int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    // (iii) Zero Matrix
    int zero = 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(A[i][j] != 0)
                zero = 0;

    if(zero)
        printf("\nA is a Zero Matrix\n");
    else
        printf("\nA is not a Zero Matrix\n");

    // (iv) Symmetric Matrix
    int symmetric = 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(A[i][j] != A[j][i])
                symmetric = 0;

    if(symmetric)
        printf("A is Symmetric\n");
    else
        printf("A is not Symmetric\n");

    // (v) Determinant - only for 3x3
    if(n == 3) {
        int det;

        det = A[0][0] * (A[1][1]*A[2][2] - A[1][2]*A[2][1])
            - A[0][1] * (A[1][0]*A[2][2] - A[1][2]*A[2][0])
            + A[0][2] * (A[1][0]*A[2][1] - A[1][1]*A[2][0]);

        printf("Determinant = %d\n", det);
    }

    // (vi) Transpose in-place
    printf("\nTranspose of A:\n");

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%d ", A[i][j]);

        printf("\n");
    }

    return 0;
}