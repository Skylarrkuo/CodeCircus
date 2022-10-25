#include <stdio.h>
#include <math.h>
#define PI 3.1415926 //π

int main(){
    float r;
    int h;
    float YZC, YMJ, QBMJ, QTJ, YZTJ;//圆周长，圆面积，圆球表面积，圆球体积，圆柱体积；
    //输入半径和高
    printf("输入半径：");
    scanf("%f",&r);
    printf("输入高:");
    scanf("%d", &h);
    //计算部分
    YZC = 2 * r * PI;
    YMJ = PI * pow(r, 2);
    QBMJ = 4 * PI * pow(r, 2);
    QTJ = (4 / 3) * PI * pow(r, 3);
    YZTJ = PI * pow(r, 2) * h;
    //输出结果
    printf("\n圆周长为:%f\n", YZC);
    printf("圆面积为:%f\n",YMJ);
    printf("圆球表面积为：%f\n",QBMJ);
    printf("圆球体积为：%f\n",QTJ);
    printf("圆柱体积为：%f",YZTJ);
    return 0;
}