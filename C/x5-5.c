//习题
#include <stdio.h>

int main(){
    int a, s, a1, n, i, j;
    printf("输入a,n用逗号隔开:");
    scanf("%d,%d", &a, &n);
    a1 = 1;
    s = 0;
    for (i = 1; i <= n;i++){
        for (j = 1; j <= i;j++){
            a1 *= a;
        }
        s += a1;
        a1 = 1;
    }
    printf("Sn=%d", s);
}