#include <stdio.h>
int gys(int x, int y);
int gbs(int x, int y);
int main()
{
    int x, y;
    printf("输入两个整数中间用逗号隔开：");
    scanf("%d,%d", &x, &y);
    printf("最大公约数为：%d\n", gys(x, y));
    printf("最小公倍数为：%d", gbs(x, y));
    return 0;
}

int gys(int x, int y)
{
    int t;
    while (y != 0)
    {
        t = y;
        y = x % y;
        x = t;
    }
    return x;
}

int gbs(int x, int y)
{
    return (x * y) / gys(x, y);
}