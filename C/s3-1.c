#include <math.h>
#include <stdio.h>

int main()
{
    float a, b, c, p;
    float area;
    printf("���������εı߳�a,b,c�ö��Ÿ���:");
    scanf("%f,%f,%f", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a)
    {
        p = (a + b + c) / 2;
        area = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("���������ε����Ϊ��%f", area);
    }
    else
    {
        printf("����ֵ�޷�����һ�������Σ�");
    }
    return 0;
}