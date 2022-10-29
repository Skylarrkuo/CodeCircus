#include <stdio.h>
int f(int x);
int main()
{

    int x, y;
    printf("输入x的值：");
    scanf("%d", &x);
    y = f(x);
    printf("函数值为：%d", y);
    return 0;
}

int f(int x)
{
    int y;
    if (x < 1)
        y = x;
    if (x >= 1 && x < 10)
        y = 2 * x - 1;
    if (x >= 10)
        y = 3 * x - 11;
    return y;
}