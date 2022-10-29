#include <stdio.h>

int main(){
    int i,sum,a;
    sum = 0;

    for (i = 1; i <= 30;i++){
        printf("输入第%d个人的成绩：", i);
        scanf("%d", &a);
        sum += a;
    }
    printf("30个同学的平均成绩为：%d", sum/30);
}