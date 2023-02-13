#include <stdio.h>

int main()
{
    int a[11] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99};
    int i, j, c, t;
    printf("现有已排好序的数组:");
    for (i = 0; i <= 10; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n输入要插入的数字:");
    scanf("%d", &c);
    for (i = 0; i < 10; i++)
    {
        if (c > a[9 - i])
        {
            for (j = 10 - i; j <= 10; j++)
            {
                t = a[j];
                a[j] = c;
                c = t;
            }
        }
    }
    for (i = 0; i <= 10; i++)
    {
        printf("%d ", a[i]);
    }
}