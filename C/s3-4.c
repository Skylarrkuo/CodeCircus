#include <stdio.h>

int main()
{
    int a;
    printf("输入0~6的数字：");
    scanf("%d", &a);
    switch (a)
    {
    case 0:
        printf("星期日");
        break;
    case 1:
        printf("星期一");
        break;
    case 2:
        printf("星期二");
        break;
    case 3:
        printf("星期三");
        break;
    case 4:
        printf("星期四");
        break;
    case 5:
        printf("星期五");
        break;
    case 6:
        printf("星期六");
        break;
    default:
        printf("输入不合规！");
        break;
    }
    return 0;
}