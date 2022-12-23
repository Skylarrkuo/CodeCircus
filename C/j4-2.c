#include <stdio.h>
int main()
{
    float x;
    printf("输入成绩:");
    scanf("%f", &x);
    if (x >= 90 && x <= 100)
        printf("优秀");
    else if (x >= 90 && x <= 100)
        printf("良好");
    else if (x >= 80 && x < 90)
        printf("中等");
    else if (x >= 70 && x < 80)
        printf("及格");
    else if (x >= 0 && x < 70)
        printf("不及格");
    else
        printf("输入错误");
    return (0);
}
