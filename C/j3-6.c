#include <stdio.h>
void bj(int *p1, int *p2, int *p3);
int main()
{
    int a, b, c;
    printf("输入三个数字:");
    scanf("%d,%d,%d", &a, &b, &c);
    bj(&a, &b, &c);
    printf("从小到大为:%d,%d,%d", a, b, c);
    return 0;
}
void bj(int *p1, int *p2, int *p3)
{
    int t;
    if (*p1 > *p2)
        t = *p1, *p1 = *p2, *p2 = t;
    if (*p2 > *p3)
        t = *p2, *p2 = *p3, *p3 = t;
    if (*p1 > *p2)
        t = *p1, *p1 = *p2, *p2 = t;
}