#include <math.h>
#include <stdio.h>

int main()
{
    float a, b, c, p;//定义变量a，b，c，p分别存储三个边长和半周长
    float area;//定义变量存储面积
    printf("输入三角形的边长a,b,c用逗号隔开:");
    scanf("%f,%f,%f", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a)//判断是否构成一个三角形
    {
        //利用海伦公式进行面积的计算
        p = (a + b + c) / 2;//
        area = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("输入三角形的面积为：%f", area);//输出结果
    }
    else
    {
        printf("输入值无法构成一个三角形！");//无法构成三角形，退出
    }
    return 0;
}