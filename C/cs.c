#include <stdio.h>

int main( ) {
 float s, money, qbjlc, qbjqs, extra;
 printf(" ��ֱ�����·�̣��𲽼�·�̣��𲽼�Ǯ���������𲽼۵ļ۸�");
 scanf("%f,%f,%f,%f", &s, &qbjlc, &qbjqs, &extra);
 if (s > 0 && s <= qbjlc)
  money = qbjqs;
 else
  money = qbjqs + (s - qbjlc) * extra;
 printf("�������Ϊ��%f\n", money);
 return 0;
}