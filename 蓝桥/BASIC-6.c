#include <stdio.h>

int main()
{
    int i, j,n;
    int a[34][34];
    scanf("%d", &n);
    for (i = 0; i < n; i++)//循环行
    {
        for (j = 0; j <= i; j++)//顺环列
        {
            if (i >= 2&&j>=1)
            {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }else{
                a[i][0] = 1;
            }
            if (i == j)
            {
                a[i][j] = 1;
            }
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}