#include<stdio.h>
// T is type, st is start, ed is end, d is distance
// 1 + 1/2 + 1/3 + ... + 1/n
#define SUM(T, st, ed, d) ({ \
    T s = 0; \
    for (int i = st; i != ed + d; i += d) \
        s += (T)1 / i; \
    s; \
})

#define n 100000

int main(){
    printf("%.16f\n", SUM(float, 1, n, 1));
    printf("%.16f\n", SUM(float, n, 1, -1));
    printf("%.16f\n", SUM(double, 1, n, 1));
    printf("%.16f\n", SUM(double, n, 1, -1));
}