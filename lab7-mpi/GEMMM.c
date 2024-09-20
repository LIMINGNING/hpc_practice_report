#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 4  // 可以修改为 8

void read_matrix_from_file(const char* filename, double M[N][N]) 
{
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        printf("无法打开文件 %s\n", filename);
        exit(-1);
    }
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (fscanf(file, "%lf", &M[i][j]) != 1) 
            {
                printf("读取文件 %s 时出错\n", filename);
                fclose(file);
                exit(-1);
            }
        }
    }
    fclose(file);
}

void print_matrix(const char* name, double M[N][N]) 
{
    // 自定义矩阵打印函数
    printf("矩阵 %s:\n", name);
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            printf("%15.6e ", M[i][j]);  // 使用科学计数法格式化输出
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char* argv[]) 
{
    int rank, size;
    double A[N][N], B[N][N], C[N][N];

    MPI_Init(&argc, &argv);                      // 初始化 MPI 环境
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);        // 获取当前进程的 rank
    MPI_Comm_size(MPI_COMM_WORLD, &size);        // 获取进程总数

    // 检查 N 是否能被进程数整除
    if (N % size != 0) 
    {
        if (rank == 0) 
        {
            printf("矩阵大小 N=%d 必须能被进程数 size=%d 整除。\n", N, size);
        }
        MPI_Finalize();
        exit(-1);
    }

    int rows_per_proc = N / size;  // 每个进程计算的行数

    MPI_Datatype rowtype;
    MPI_Type_contiguous(N, MPI_DOUBLE, &rowtype);
    MPI_Type_commit(&rowtype);

    if (rank == 0) 
    {
        // 主进程
        // 从文件中读取矩阵 A、B、C
        read_matrix_from_file("data41.txt", A);
        read_matrix_from_file("data42.txt", B);
        read_matrix_from_file("data4c.txt", C);  // 确保 C 初始化为 0

        // 将矩阵 B 发送给所有进程
        MPI_Bcast(&(B[0][0]), N*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        // 将矩阵 A 的相应行发送给各进程
        for (int p = 1; p < size; p++) {
            MPI_Send(&(A[p*rows_per_proc][0]), rows_per_proc, rowtype, p, 0, MPI_COMM_WORLD);
        }

        // 主进程计算自己负责的部分
        for (int i = 0; i < rows_per_proc; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                C[i][j] = 0;  // 确保 C 初始为 0
                for (int k = 0; k < N; k++) 
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        // 接收其他进程的计算结果
        for (int p = 1; p < size; p++) 
        {
            MPI_Recv(&(C[p*rows_per_proc][0]), rows_per_proc, rowtype, p, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        // 打印矩阵 A、B、C
        print_matrix("A", A);
        print_matrix("B", B);
        print_matrix("C", C);

    } 
    else 
    {
        // 非主进程
        // 接收矩阵 B
        MPI_Bcast(&(B[0][0]), N*N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        // 接收矩阵 A 的相应行
        MPI_Recv(&(A[rank*rows_per_proc][0]), rows_per_proc, rowtype, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // 初始化矩阵 C 的对应部分
        for (int i = rank*rows_per_proc; i < (rank+1)*rows_per_proc; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                C[i][j] = 0;
            }
        }

        // 打印接收到的数据以确认通信正确
        printf("进程 %d 已接收到矩阵 A 的行和矩阵 B。\n", rank);

        // 计算自己负责的部分
        for (int i = rank*rows_per_proc; i < (rank+1)*rows_per_proc; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                for (int k = 0; k < N; k++) 
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        // 将计算结果发送回主进程
        MPI_Send(&(C[rank*rows_per_proc][0]), rows_per_proc, rowtype, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Type_free(&rowtype);
    MPI_Finalize();  // 结束 MPI 环境
    return 0;
}
