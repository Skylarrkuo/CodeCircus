#include <stdio.h>
void bj(int *p1, int *p2);
int main()
{
    int a, b;
    printf("输入两个数字:");
    scanf("%d,%d", &a, &b);
    bj(&a, &b);
    printf("从大到小为:%d,%d", a, b);
    return 0;
}
void bj(int *p1, int *p2)
{
    int t;
    if (*p1 < *p2)
    {
        t = *p1;
        *p1 = *p2;
        *p2 = t;
    }
}