#include <stdio.h>

int main( ) {
 float s, money, qbjlc, qbjqs, extra;
 printf(" 请分别输入路程，起步价路程，起步价钱数，超过起步价的价格：");
 scanf("%f,%f,%f,%f", &s, &qbjlc, &qbjqs, &extra);
 if (s > 0 && s <= qbjlc)
  money = qbjqs;
 else
  money = qbjqs + (s - qbjlc) * extra;
 printf("输出车费为：%f\n", money);
 return 0;
}