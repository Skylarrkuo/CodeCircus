//习题
#include <stdio.h>

int main(){
    int m, n, s,t;
    printf("输入两个数,用逗号隔开:");
    scanf("%d,%d", &m, &n);
    s = m * n;
    while (n!=0)
    {
        t = n;
        n = m % n;
        m = t;
    }
    s = s / m;
    printf("最大公约数为:%d\n最小公倍数为:%d", m,s);
    return 0;
}