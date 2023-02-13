#include <stdio.h>

int main(){
    int i, j;
    //外循环输出1~9的第二个乘数
    for (i = 1; i <= 9;i++){
        //内循环负责1~9的第一个乘数
        for (j = 1; j <= i;j++){
            printf("%dx%d=%d\t", j, i, i * j);
        }
        //输出完成一行后换行
        printf("\n");
    }
    return 0;
}