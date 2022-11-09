#include <stdio.h>

int main()
{
    double weight;//定义变量存储重量
    double money;//定义变量存储金额
    printf("输入行李重量：");
    scanf("%lf", &weight);
    if (weight <= 20.0)//如果小于20kg时为免费
    {
        printf("免费！！！\n");
        money = 0;
    }
    else if (weight > 20.0 && weight <= 40.0)
    {
        //计算重量在20~40kg时的范围时所需的费用
        money = (weight - 20) * 0.1;
    }
    else if (weight > 40)
    {
        //计算重量大于40kg时所需的费用
        money = (weight - 20) * 0.08;
    }
    printf("所需金额为：%f元", money);

    return 0;
}