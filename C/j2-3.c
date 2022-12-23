#include <stdio.h>
int s(int x); // 定义用与判断输入数是否为素数的函数
int main()
{
    int x, y;
    printf("输入一个数：");
    scanf("%d", &x);
    if (s(x))                   // 判断返回值，1为true，0为false
        printf("%d是素数!", x); // 为真时输出是素数
    else
        printf("%d不是素数!", x); // 为假时输出不是素数
    return 0;
}
int s(int x)
{
    int i; // 用穷举法判断该数是否为素数
    for (i = 2; i < x; i++)
    {
        if (x % i == 0) // 一旦 该数 可以被 2到除它之外值之间的数 整除 就退出循环
            break;
    }
    if (i == x)   // 如果该数 始终 没有被整除则可以完整的执行完循环，此时x=i
        return 1; // 返回1表示为素数
    else          // 如果中途退出则x！=i
        return 0; // 返回0表示不为素数
}