#include<stdio.h>

int main(){

    char s[] = "hello world";
    char c = s[20];
    printf("c=%c\n", c);
    s[20]='a';
    c = s[20];
    printf("c=%c\n", c);
}
