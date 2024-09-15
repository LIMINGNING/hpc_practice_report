#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
void MY_MMult(int m, int n, int k, double *a, int lda,
               double *b, int ldb,
               double *c, int ldc)
{
    int i, j, l;

    #pragma omp parallel for collapse(2) private(i, j, l)
    for (i = 0; i < m; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            double sum = c[i * ldc + j];  // 从现有的C_ij开始
            for (l = 0; l < k; l++) 
            {
                sum += a[i * lda + l] * b[l * ldb + j];
            }
            c[i * ldc + j] = sum;
        }
    }
}