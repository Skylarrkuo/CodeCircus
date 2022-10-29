#include <math.h>
#include <stdio.h>

int main()
{
    int a, i;
    int b;
    i = 0;
    while (i != 1)
    {
        printf("输入一个小于1000的正数：");
        scanf("%d", &a);
        if (a >= 0 && a <= 1000)
        {
            b = sqrt(a);
            printf("%d的平方根为：%d\n", a, b);
        }
        else
        {
            printf("输入不合规！\n");
        }
        printf("0继续1退出:");
        scanf("%d", &i);
    }
}