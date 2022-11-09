#include <stdio.h>

int main()
{
    int a[21];
    int b, i;
    a[1] = 1;
    a[2] = 1;

    for (i = 1; i <= 20; i++)
    {
        if (i <= 2)
        {
            printf("%d\t", a[i]);
        }
        else
        {
            a[i] = a[i - 2] + a[i - 1];
            printf("%d\t", a[i]);
        }
        b++;
        if (b % 5 == 0)
            printf("\n");
    }
    return 0;
}