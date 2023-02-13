#include <stdio.h>

int main()
{
    int i, j;
    int n, m, t = 0;
    char c[27];
    for (i = 1; i <= 26; i++)
    {
        c[i] = '@' + i;
    }
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        if (i % 26 == 0)
            j = 26;
        else
            j = i % 26;
        for (; j > 1; j--)
        {

            printf("%c", c[j]);
            t++;
            if (t >= m)
                break;
        }
        for (j = 1; j <= m - t; j++)
        {
            printf("%c", c[j]);
        }
        printf("\n");
        t = 0;
    }
    return 0;
}