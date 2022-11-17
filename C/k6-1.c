#include <stdio.h>
//杨辉三角
int main()
{
    int i, j, b;
    int a[10][10];

    for (i = 0; i < 10; i++)
    { 
        for (j = 0; j <= i; j++)
        {
            if (i >= 2 && j >= 1)
            {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
            else
            {
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