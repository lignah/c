#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 8
#define EPSILON 1e-7

void matmul(double a[N][N], double b[N][N], double res[N][N]) {
    int i, j, k;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            res[i][j] = 0.0;
            for (k = 0; k < N; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
}

int inverse(double mat[N][N], double inv[N][N]) {
    int i, j, k;
    double tmp;
    double aug[N][2*N];

    memset(aug, 0, sizeof(aug));
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            aug[i][j] = mat[i][j];
            aug[i][j+N] = (i == j) ? 1.0 : 0.0;
        }

    for (i = 0; i < N; i++) {
        if (fabs(aug[i][i]) < EPSILON)
            return 0;
        tmp = aug[i][i];
        for (j = 0; j < 2*N; j++)
            aug[i][j] /= tmp;
        for (k = 0; k < N; k++) {
            if (k != i) {
                tmp = aug[k][i];
                for (j = 0; j < 2*N; j++)
                    aug[k][j] -= aug[i][j] * tmp;
            }
        }
    }
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            inv[i][j] = aug[i][j+N];
    return 1;
}

int main(void) {
    double A[N][N], B[N][N], C[N][N], invA[N][N];
    int i, j;
    srand(0820);

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            A[i][j] = rand() % 10 + 1;
            B[i][j] = rand() % 5;
        }

    matmul(A, B, C);

    if (inverse(A, invA)) {
        printf("Successfully computed the inverse matrix of A\12");
        double check[N][N];
        matmul(A, invA, check);
        printf("A * invA (Should be an identity matrix):\12");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++)
                printf("%.2f ", check[i][j]);
            printf("\12");
        }
    } else {
        printf("Failed to compute the inverse matrix\12");
    }

    return 0;
}