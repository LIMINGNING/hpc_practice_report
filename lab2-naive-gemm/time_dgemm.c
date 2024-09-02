#include "stdio.h"
#include "stdlib.h"
#include "sys/time.h"
#include "time.h"
#include <cblas.h>

void dgemm(int m, int n, int k, double alpha, double beta, double *A, double *B, double *C)  
{  
    for(int i = 0; i < m; i++)  
    {    
        for(int j = 0; j < n; j++)  
        {  
            C[i * n + j] = beta * C[i * n + j];  
            for(int p = 0; p < k; p++)  
            {  
              C[i * n + j] += alpha * A[i * k + p] * B[p * n + j];   
            }  
        }  
    }  
}  



void printf_matrix(int row, int col, double matrix[row][col] )
{
  for(int i=0; i<row; i++)
  {
    for(int j=0; j<col;j++)
    {
      printf("%lf ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

// 编译 gcc -o time_dgemm time_dgemm.c –lopenblas
// 运行 ./time_dgemm 1024
int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Input Error\n");
    return 1;
  }

  printf("test!\n");
  int i, m, n, k;
  m = n = k = atoi(argv[1]);

  int sizeofa = m * k;
  int sizeofb = k * n;
  int sizeofc = m * n;
  int lda = m;
  int ldb = k;
  int ldc = m;

  double alpha = 1.2;
  double beta = 0.001;

  struct timeval start, finish;
  double duration;

  double *A = (double *)malloc(sizeof(double) * sizeofa);
  if (!A) 
  {  
    perror("Failed to allocate memory for A");  
    exit(EXIT_FAILURE);  
  }  
  double *B = (double *)malloc(sizeof(double) * sizeofb);
  if (!B) 
  {  
    perror("Failed to allocate memory for A");  
    exit(EXIT_FAILURE);  
  }  
  double *C = (double *)malloc(sizeof(double) * sizeofc);
  if (!C) 
  {  
    perror("Failed to allocate memory for A");  
    exit(EXIT_FAILURE);  
  }  
  srand((unsigned)time(NULL));

  for (i = 0; i < sizeofa; i++)
  {
    A[i] = i % 3 + 1; // (rand() % 100) / 100.0;
  }

  for (i = 0; i < sizeofb; i++)
  {
    B[i] = i % 3 + 1; //(rand()%100)/10.0;
  }

  for (i = 0; i < sizeofc; i++)
  {
    C[i] = 0.1;
  }
  
  printf("m=%d,n=%d,k=%d,alpha=%lf,beta=%lf,sizeofc=%d\n", m, n, k, alpha, beta, sizeofc);
  gettimeofday(&start, NULL);
  cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
  gettimeofday(&finish, NULL);
  /*
  for (i = 0; i < sizeofc; i++)
  {
    printf("%lf\n",C[i]);
  }
  */
  // 转成成秒数
  duration = (double)(finish.tv_sec - start.tv_sec) + (double)(finish.tv_usec - start.tv_usec) / 1.0e6;
  double gflops = 4.0 * m * n * k;
  gflops = gflops / duration * 1.0e-9;

  FILE *fp;
  fp = fopen("timeDGEMM.txt", "a"); // 追加写
  fprintf(fp, "%dx%dx%d\t%lf s\t%lf GFLOPS\n", m, n, k, duration, gflops);
  fclose(fp);
  
  gettimeofday(&start, NULL);
  dgemm(m,n,k,alpha,beta,A,B,C);
  gettimeofday(&finish, NULL);
  /*
  for (i = 0; i < sizeofc; i++)
  {
    printf("%lf\n",C[i]);
  }
  */
  duration = (double)(finish.tv_sec - start.tv_sec) + (double)(finish.tv_usec - start.tv_usec) / 1.0e6;
  gflops = 4.0 * m * n * k;
  gflops = gflops / duration * 1.0e-9;

  //FILE *fp;
  fp = fopen("timeDGEMM.txt", "a"); // 追加写
  fprintf(fp, "%dx%dx%d\t%lf s\t%lf GFLOPS\n", m, n, k, duration, gflops);
  fclose(fp);
  
  free(A);
  free(B);
  free(C);
  return 0;
}
