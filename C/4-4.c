#include <stdio.h>

int main()
{
    int a, b, c, max;
    printf("输入三个数，用逗号隔开：");
    scanf("%d,%d,%d", &a, &b, &c);
    max = a;
    if (max < b)
        max = b;
    if (max < c)
        max = c;
    printf("max=%d", max);
    return 0;
}