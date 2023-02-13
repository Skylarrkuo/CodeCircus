#include <stdio.h>

int main()
{
    int a[10], i;
    //对数组进行赋值
    for (i = 0; i <= 9; i++)
    {
        a[9 - i] = i;
    }
    //对数组进行倒序输出
    for (i = 0; i < 9; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}