#include <stdio.h>

#define M 3
#define N 3
#define K 2

void sgemm(int m, int n, int k, int beta,
           float *A, int lda, float *B, int ldb, float *C, int ldc)
{
    for (int i = 0; i < m; i++)
    { // C[i]
        for (int j = 0; j < n; i++)
        { // should be j++
            for (int p = 0; p < k; p++)
            {
                C[i * ldc + j] += A[i * lda + p] * B[p * ldb + j];
            }
        }
    }
}

void printf_matrix(int row, int col, float *matrix)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%f ", matrix[i * col + j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void main()
{
    float A[] = {1.0, -3.0, 2.0, 4.0, 1.0, -1.0};
    float B[] = {1.0, 2.0, 1.0, -3.0, 4.0, -1.0};
    float C[] = {.5, .5, .5, .5, .5, .5, .5, .5, .5};

    // C= A*B + C
    sgemm(M, N, K, 2, A, 2, B, 3, C, 3);

    printf_matrix(M, K, A);
    printf_matrix(K, N, B);
    printf_matrix(M, N, C);
}
