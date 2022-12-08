#include <stdio.h>

int main()
{
    float s;//定义存储路程的变量
    float mony;//定义存储所需金额的变量
    printf("输入里程数：");
    scanf("%f", &s);
    //如果小于三公里只要起步价，如果大于则减去起步里程计算额外费用相加
    if (s <= 3 && s >= 0)
    
    {
        mony = 6;
    }
    else
    {
        mony = 6 + (s - 3) * 1.5;
    }
    printf("车费为：%f元", mony);//输出结果
    return 0;
}