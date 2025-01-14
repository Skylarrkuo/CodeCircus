#include <stdio.h>
#include <math.h>

int main()
{
    float p, r, n;
    r = 0.07;
    n = 10;
    p = pow(1 + r, n);
    printf("十年之后我国国民生产总值与增长了%f%%", p);
    return 0;
}