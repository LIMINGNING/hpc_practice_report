#include <stdio.h>
#include <cblas.h>
#include "defs.h"

/* Routine for computing C = A * B + C */

void MY_MMult(int m, int n, int k, double *a, int lda,
              double *b, int ldb,
              double *c, int ldc)
{
  int alpha=1;
  int beta=1;
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
}
