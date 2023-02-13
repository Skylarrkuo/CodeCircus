#include <stdio.h>

int main(){
    int a, b, c, i;
    //最外层循环用于输出4行数字
    for (i = 1; i <= 4;i++){
        //内第一个循环用于输出前置空格
        for (b = 1; b <= i * 2 - 1;b++)
        {
            printf(" ");
        }
        //内置第二个循环用于输出每一行的数字阵列
        for (a = 1; a <= 8 - (i*2-1); a++){
            c = 10 - i;
            printf("%d ", c);
        }
        printf("\n");
    }
    return 0;
}