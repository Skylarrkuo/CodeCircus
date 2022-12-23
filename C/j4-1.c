#include <stdio.h>
#include <math.h>

int main()
{
    double x, y;
    printf("输入x的值:");
    scanf("%lf", &x);
    if (x <= 1.0)//按输入数所属于的范围分别进行计算
        y = sin(x) - (1.0 / 3.0);
    else if (x > 1.0 && x < 10.0)
        y = sqrt(2 * x - 1);
    else if (x >= 10.0)
        y = fabs(10 - 5 * x);

    printf("y的值为:%.2f", y);
    return (0);
}
