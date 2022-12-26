#include <stdio.h>

int main()
{
    int n, i;
    long a[11];
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%x", &a[i]);
    }
    for (i = 1; i <= n; i++)
    {
        printf("%ho\n", a[i]);
    }
    return 0;
}