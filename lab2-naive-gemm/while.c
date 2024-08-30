#include <stdio.h>
#include <unistd.h>

int main()
{
    int a = 0;

    while (1)
    {
        a++;
        if ((a % 100000000) == 0)
        {
            sleep(1);
            printf("a = %d\n", a);
        }
    }
}
