#include <stdio.h>

int main()
{
    float s;
    float mony;
    printf("输入里程数：");
    scanf("%f", &s);
    if (s <= 3 && s >= 0)
    {
        mony = 6;
    }
    else
    {
        mony = 6 + (s - 3) * 1.5;
    }
    printf("车费为：%f元", mony);

    return 0;
}