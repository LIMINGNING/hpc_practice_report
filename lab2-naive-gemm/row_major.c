#include <stdio.h>

#define M 3
#define K 2

void printf_addr(int row, int col, double matrix[row][col] ){
  for(int i=0; i<row; i++){
    for(int j=0; j<col;j++){
        printf("matrix[%d][%d] addr:0x%lx\n", i, j, (long unsigned int)&matrix[i][j]);
    }
    printf("\n");
  }
}


void main()
{
    double A[M][K] = { {1.0,  -3.0},
                      {2.0,  4.0},
                      {1.0, -1.0} };         

    printf_addr(M,K,A);

}


