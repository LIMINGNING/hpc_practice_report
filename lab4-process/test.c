#include <stdio.h>
#include <stdlib.h>

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

// 编译 gcc -o time_dgemm time_dgemm.c –lopenblas
// 运行 ./time_dgemm 1024
int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Input Error\n");
    return 1;
  }

  int i, m, n, k;
  m = n = k = atoi(argv[1]);

  int sizeofa = m * k;
  int sizeofb = k * n;
  int sizeofc = m * n;
  int lda = m;
  int ldb = k;
  int ldc = m;

  double alpha = 1.0;
  double beta = 1.0;

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

  int rc=fork();
  if (rc < 0) 
  {      
    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  }

  else if (rc == 0) 
  {
    // child (new process)
    dgemm(m,n,k,alpha,beta,A,B,C);
  }
  else
  {
    dgemm(m,n,k,alpha,beta,A,B,C);
  }
  
  free(A);
  free(B);
  free(C);
  return 0;
}