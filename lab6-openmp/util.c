#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "defs.h"

static double gtod_ref_time_sec = 0.0;

/* Adapted from the bl2_clock() routine in the BLIS library */

double dclock()
{
  double the_time, norm_sec;
  struct timeval tv;

  gettimeofday(&tv, NULL);

  if (gtod_ref_time_sec == 0.0)
    gtod_ref_time_sec = (double)tv.tv_sec;

  norm_sec = (double)tv.tv_sec - gtod_ref_time_sec;

  the_time = norm_sec + tv.tv_usec * 1.0e-6;

  return the_time;
}

double compare_matrices(int m, int n, double *a, int lda, double *b, int ldb)
{
  int i, j;
  double max_diff = 0.0, diff;

  for (j = 0; j < n; j++)
    for (i = 0; i < m; i++)
    {
      diff = abs(A(i, j) - B(i, j));
      max_diff = (diff > max_diff ? diff : max_diff);
    }

  return max_diff;
}

void copy_matrix(int m, int n, double *a, int lda, double *b, int ldb)
{
  int i, j;

  for (j = 0; j < n; j++)
    for (i = 0; i < m; i++)
      B(i, j) = A(i, j);
}

void print_rowmajor_matrix(int m, int n, double *a, int lda)
{
  int i, j;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      // printf("%le ", a[(i)*lda + (j)]);
      printf("%f ", a[(i)*lda + (j)]);
    }
    printf("\n");
  }
  printf("\n");
}

void print_colmajor_matrix(int m, int n, double *a, int lda)
{
  int i, j;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%f ", a[(j)*lda + (i)]);
    }
    printf("\n");
  }
  printf("\n");
}

void random_matrix(int m, int n, double *a, int lda)
{
  /* drand48() generate pseudo-random numbers using the linear congruential algorithm and
     48-bit integer arithmetic. return nonnegative double-precision floating-point values
     uniformly distributed over the interval [0.0, 1.0). */
  double drand48();
  int i, j;

  for (j = 0; j < n; j++)
    for (i = 0; i < m; i++)
      // A(i, j) = drand48();
      A(i, j) = 2.0 * drand48() - 1.0;
}

void zero_matrix(int m, int n, double *a, int lda)
{
  int i, j;

  for (j = 0; j < n; j++)
    for (i = 0; i < m; i++)
      A(i, j) = 0;
}
