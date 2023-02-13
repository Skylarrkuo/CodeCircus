#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, j, l;
    char a[10][100001];
    long x = 0, b = 0;
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        gets(a[i]);
    }
    for (i = 1; i <= n; i++)
    {
        for (l = 0; a[i][l] != '\0'; l++)
            ;
        for (j = 0; a[i][j] != '\0'; j++)
        {
            if (a[i][j] >= '0' && a[i][j] <= '9')
                x += (a[i][j] - '0') * pow(16, --l);
            else if (a[i][j] >= 'A' && a[i][j] <= 'F')
                x += (a[i][j] - 55) * pow(16, --l);
        }
        for (j = 0; x / 8 != 0; j++)
        {
            b += (x % 8) * pow(10, j);
            x /= 8;
        } 
        b += x * pow(10, j);
        printf("%d\n", b);
        b = 0;
        x = 0;
    }
    return 0;
}