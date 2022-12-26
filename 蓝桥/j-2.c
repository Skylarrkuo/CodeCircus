#include <stdio.h>
int main()
{
    int a[201], n, i, j, t;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}