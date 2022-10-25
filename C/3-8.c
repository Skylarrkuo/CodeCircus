#include <stdio.h>

int main( ) {
 int a, b, c, d, e, f;
 scanf("%d", &f);
 a = f % 10;
 b = (f / 10) %10;
 c = (f /100) % 10;
 e = f / 1000;
 d = a * 1000 + b * 100 + c * 10 + e;
 printf("这四位数是：%d\n颠倒后为:%d",f,d);
 return 0;

}