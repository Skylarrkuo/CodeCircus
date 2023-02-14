#include <stdio.h>
int dg(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return dg(n - 1) + dg(n - 2);
}
int main()
{
    int a, i;
    printf("请输入斐波那契额数列个数");
    scanf("%d", &a);
    for (i = 1; i <= a; i++)
    {
        if (i % 5 == 0)
            printf("   ");
        printf("%3d", dg(i));
    }
}