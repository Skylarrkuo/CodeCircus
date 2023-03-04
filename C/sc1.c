#include <stdio.h>
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6}, *p = a, i, sum = 0;
    for (i = 1; i < 6; i++)
        sum += *(p++);
    printf("%d", sum);
    return 0;
}