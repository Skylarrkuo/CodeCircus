#include <stdio.h>

int main(){
    int i,sum,a;
    sum = 0;

    for (i = 1; i <= 30;i++){
        printf("输入第%d个同学的成绩：", i);
        scanf("%d", &a);
        sum += a;
    }
    printf("30位同学的平均分为：%d", sum/30);
}