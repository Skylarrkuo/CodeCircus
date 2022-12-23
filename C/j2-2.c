#include <stdio.h>
#include <math.h>
int x1(int a, int b, int c);//声明用于求Δ>0时解的函数
int x2(int a, int b, int c);//声明用于求Δ=0时解的函数
int x3(int a, int b, int c);//声明用于求Δ<0时解的函数
int main()
{
    int a, b, c;
    printf("输入一元二次方程标准式的系数a,b,c:");
    scanf("%d,%d,%d", &a, &b, &c);//获取一元二次放长系数
    //判断Δ的情况
    if ((b * b - 4 * a * c) > 0)//当Δ>0
        x1(a, b, c);
    else if ((b * b - 4 * a * c) == 0)//当Δ=0
        x2(a, b, c);
    else if ((b * b - 4 * a * c) < 0)//当Δ<0
        x3(a, b, c);
    return 0;
}
int x1(int a, int b, int c)//当Δ>0时，方程有2个解
{
    int y1, y2;//定义用于存储解x1，x2的变量
    y1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;//求根公式 +情况
    y2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;//求根公式 -情况
    printf("%dx^2+%dx+%d=0的解为:\n", a, b, c);//输出解
    printf("x1=%d,x2=%d", y1, y2);
}
int x2(int a, int b, int c)//当Δ=0时，方程有1个解
{
    int y;//定义存储唯一解的变量y
    y = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;//用任意一种情况的求根公式求解
    printf("%dx^2+%dx+%d=0的解为:\n", a, b, c);//输出结果
    printf("x=%d", y);
}
int x3(int a, int b, int c)//当Δ<0时，方程无解
{
    printf("%dx^2+%dx+%d=0的解为:\n无解", a, b, c);//直接输出结果
}
