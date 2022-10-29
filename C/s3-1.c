#include <math.h>
#include <stdio.h>

int main()
{
    float a, b, c, p;
    float area;
    printf("输入三角形的边长a,b,c用逗号隔开:");
    scanf("%f,%f,%f", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a)
    {
        p = (a + b + c) / 2;
        area = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("输入三角形的面积为：%f", area);
    }
    else
    {
        printf("输入值无法构成一个三角形！");
    }
    return 0;
}