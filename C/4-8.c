#include <stdio.h>

int main()
{
    int cj;
    printf("����ɼ���");
    scanf("%d", &cj);
    printf("/n�ɼ��ȼ�Ϊ��");
    switch (cj)
    {
    case 90 ... 100:
        printf("A");
        break;
    case 80 ... 89:
        printf("B");
        break;
    case 70 ... 79:
        printf("c");
        break;
    case 60 ... 69:
        printf("D");
        break;
    case 0 ... 59:
        printf("E");
        break;
    default:
        break;
    }

    return (0);
}