#include <stdio.h>
void zf(int x);
int main()
{
    int x, y;
    printf("输入一个四位数字:");
    scanf("%d", &x);
    zf(x);
    return 0;
}

void zf(int x)
{
    int i;
    char c[4];
    for (i = 3; i >= 0; i--)
    {
        c[i] = x % 10 + '0';
        x /= 10;
    }
    for (i = 0; i < 4; i++)
    {
        printf("%c ", c[i]);
    }
}