#include <stdio.h>

int main()
{
    int a = 10, b = 20;     // 定义两个整型变量 a 和 b
    int *p1 = &a, *p2 = &b; // 定义两个指向整型的指针变量 p1 和 p2

    // 输出 a 和 b 的值
    printf("a = %d, b = %d\n", a, b);

    // 通过指针变量输出 a 和 b 的值
    printf("*p1 = %d, *p2 = %d\n", *p1, *p2);

    return 0;
}
