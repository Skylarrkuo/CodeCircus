#include <stdio.h>

int main()
{
    int a;
    printf("����0~6�����֣�");
    scanf("%d", &a);
    switch (a)
    {
    case 0:
        printf("������");
        break;
    case 1:
        printf("����һ");
        break;
    case 2:
        printf("���ڶ�");
        break;
    case 3:
        printf("������");
        break;
    case 4:
        printf("������");
        break;
    case 5:
        printf("������");
        break;
    case 6:
        printf("������");
        break;
    default:
        printf("���벻�Ϲ棡");
        break;
    }
    return 0;
}