#include <stdio.h>

int main()
{
    float s;
    float mony;
    printf("�����������");
    scanf("%f", &s);
    if (s <= 3 && s >= 0)
    {
        mony = 6;
    }
    else
    {
        mony = 6 + (s - 3) * 1.5;
    }
    printf("����Ϊ��%fԪ", mony);

    return 0;
}