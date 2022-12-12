#include <stdio.h>
int fibo(int x);
int main()
{
    int i;
    // 输出前 10 个数
    for (i = 1; i <= 10; i++) {
        printf("%d ", fibo(i));
    }
    return 0;
}
// x 表示求数列中第 x 个位置上的数的值
int fibo(int x) {
    // 设置结束递归的限制条件
    if (x == 1 || x == 2) {
        return 1;
    }
    return fibo(x - 1) + fibo(x - 2);
}