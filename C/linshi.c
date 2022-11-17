#include <stdio.h>

int main()
{
    int x, a, i, t;//输入数据，存储某一位的变量，循环变量，位数
    printf("input:");
    scanf("%d", &x);
    t = 0;//位数初始化
    a = x;//临时存储输入数据

    //一位一位的消除，并统计位数 ，直到a=0
    while (a != 0)

    {
        a = a / 10;
        t++;
    }
    //输出
    for (i = 1; i <= t; i++)
    {
        printf("\r");//输出位置移到头部
        for (int f = 1; f <= t - i; f++) printf("  ");//确定输出位置
        //一位一位的输出然后消除
        a = x % 10;
        printf("%d ", a);
        x /= 10;
    }
}
