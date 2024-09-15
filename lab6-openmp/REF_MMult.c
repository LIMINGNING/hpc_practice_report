#include "defs.h"

/* Routine for computing C = A * B + C */

void REF_MMult(int m, int n, int k, double *a, int lda,
               double *b, int ldb,
               double *c, int ldc)
{
  int i, j, p;

  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      for (p = 0; p < k; p++)
      {
        C(i, j) = C(i, j) + A(i, p) * B(p, j);
      }
    }
  }
}
