#include <stdio.h>

int main(){
    int i, n, sum;          //循环变量
    sum = 0;//初始化求和变量
    printf("ipnut n:");//输入项数
    scanf("%d", &n);

    for (i = 1; i <= n;i++){
        sum += i * (i + 1);//循环计算相加
    }
    printf("sum=%d", sum);//输出结果
    return 0;
}