#include <stdio.h>

int main()
{
    int a[10], i, j, t;//声明所需的数组和变量
    printf("输入十个整数：\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);//循环输入整数
    }
    //用选择排序法对输入的数进行排序
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    //输出排序后的结果
    printf("输入的数从小到大排序为：\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}