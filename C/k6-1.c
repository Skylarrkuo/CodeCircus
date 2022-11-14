#include <stdio.h>

int main()
{
    int i, j;
    int a[10][10];
    for (i = 0; i < 10; i++)
    {
        a[i][0] = 1;
        for (j = 1; j <= i; j++)
        {
            if (i > 2&&j>=1)
            {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }else{
                a[i][j] = 1;
                a[i][0] = 1;
            }

            if (i == j)
            {
                a[i][j] = 1;
            }
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}