#include <stdio.h>

int main()
{
    double weight;
    double money;
    printf("��������������");
    scanf("%lf", &weight);
    if (weight <= 20.0)
    {
        printf("��ѣ�����\n");
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
    printf("������Ϊ��%fԪ", money);

    return 0;
}