#include <stdio.h>

int main()
{
    double weight;
    double money;
    printf("输入行李重量：");
    scanf("%lf", &weight);
    if (weight <= 20.0)
    {
        printf("免费！！！\n");
        money = 0;
    }
    else if (weight > 20.0 && weight <= 40.0)
    {
        money = (weight - 20) * 0.1;
    }
    else if (weight > 40)
    {
        money = (weight - 20) * 0.08;
    }
    printf("所需金额为：%f元", money);

    return 0;
}