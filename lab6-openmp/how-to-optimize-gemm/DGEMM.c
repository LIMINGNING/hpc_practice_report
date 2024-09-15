#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
// 线程数据结构
typedef struct
{
    int start_row;
    int end_row;
    int start_col;
    int end_col;
    int n; // 矩阵列数
    const double *a;
    const double *b;
    double alpha, beta;
    double *c;
} thread_data;

// 线程处理函数
void *matrix(void *arg)
{
    thread_data *data = (thread_data *)arg;
    int start_row = data->start_row;
    int start_col = data->start_col;
    int end_row = data->end_row;
    int end_col = data->end_col;
    const double *a = data->a;
    const double *b = data->b;
    double *c = data->c;
    int n = data->n;

    for (int i = start_row; i < end_row; i++)
    {
        for (int j = start_col; j < end_col; j++)
        {
            double sum = 0.0;
            for (int k = 0; k < n; k++)
            {
                sum += a[i * n + k] * b[k * n + j];
            }
            c[i * n + j] = sum;
        }
    }

    pthread_exit(NULL);
}

void MY_MMult(int m, int n, int k, double *a, int lda,
              double *b, int ldb,
              double *c, int ldc)
{
    int block;

    if (m % 16 == 0 && n % 16 == 0 && k % 16 == 0)
    {
        block = m / 16;
    }
    else
    {
        printf("Error: 矩阵不能被分");
        return;
    }

    pthread_t threads[(m / block) * (n / block)];
    thread_data matrix_thread[(m / block) * (n / block)];
    int threads_count = 0;

    for (int start_row = 0; start_row < m; start_row += block)
    {
        int end_row = start_row + block;
        if (end_row > m)
        {
            end_row = m;
        }
        for (int start_col = 0; start_col < n; start_col += block)
        {
            int end_col = start_col + block;
            if (end_col > n)
            {
                end_col = n;
            }
            matrix_thread[threads_count].start_row = start_row;
            matrix_thread[threads_count].end_row = end_row;
            matrix_thread[threads_count].start_col = start_col;
            matrix_thread[threads_count].end_col = end_col;
            matrix_thread[threads_count].n = n;
            matrix_thread[threads_count].a = a;
            matrix_thread[threads_count].b = b;
            matrix_thread[threads_count].c = c;
            pthread_create(&threads[threads_count], NULL, matrix, (void *)&matrix_thread[threads_count]);
            threads_count++;
        }
    }

    for (int i = 0; i < threads_count; i++)
    {
        pthread_join(threads[i], NULL);
    }
}