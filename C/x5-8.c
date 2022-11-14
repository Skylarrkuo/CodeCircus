//习题
#include <math.h>
#include <stdio.h>

int main()
{
    int a, b, c, i;
    for (i = 100; i <= 999; i++)
    {
        a = i % 10;
        b = i / 10 % 10;
        c = i / 100;
        if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i)
        {
            printf("%d\t", i);
        }
    }
    return 0;
}