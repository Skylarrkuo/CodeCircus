#include <stdio.h>

int main()
{
    int a, i, j;
    a = 0;
    printf("1000~2000之间所有的素数为：\n");
    for (i = 1000; i <= 2000; i++) // 循环从1000~2000进行遍历
    {
        for (j = 2; j < i; j++) //对每个数一次相除进行判断是否为素数
        {
            if (i % j == 0)//如果可以整除则直接退出
                break;
        }
        if (i == j)//否则为素数
        {
            printf("%d\t", i);
            a++;
            if (a % 8 == 0)//设置每输出八个数字换行一次
                printf("\n");
        }
    }
    return 0;
}