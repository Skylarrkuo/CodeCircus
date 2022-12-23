#include <stdio.h>
int gys(int m, int n); // 声明用于求公约数的函数
int gbs(int m, int n); // 声明用于求公倍数的函数
int main()
{
    int m, n;//存储两个数
    printf("输入两个数，用逗号隔开：");
    scanf("%d,%d", &m, &n);
    printf("最大公约数为:%d\n", gys(m, n));
    printf("最小公倍数为:%d\n", gbs(m, n));
    return 0;
}
int gys(int m, int n)
{
    int t;
    //采用辗转相除法求最大公约数
    //以m存储最后的最大公约数
    while (n != 0)
    {
        t = n;
        n = m % n;
        m = t;
    }
    return m;//返回最大公约数
}

int gbs(int m, int n)
{
    //最小公倍数=两数乘积/两数最大公约数
    return (m * n) / gys(m, n);//返回最小公倍数
}