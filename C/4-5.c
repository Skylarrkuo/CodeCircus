#include <math.h>
#include <stdio.h>

int main()
{
    int a, i;
    int b;
    i = 0;
    while (i != 1)
    {
        printf("����һ��С��1000��������");
        scanf("%d", &a);
        if (a >= 0 && a <= 1000)
        {
            b = sqrt(a);
            printf("%d��ƽ����Ϊ��%d\n", a, b);
        }
        else
        {
            printf("���벻�Ϲ棡\n");
        }
        printf("0����1�˳�:");
        scanf("%d", &i);
    }
}