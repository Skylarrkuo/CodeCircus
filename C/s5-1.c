#include <stdio.h>

int main()
{
    int a[10], i;
    for (i = 0; i <= 9; i++)
    {
        a[9 - i] = i;
    }
    for (i = 0; i < 9; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}