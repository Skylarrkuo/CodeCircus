#include <stdio.h>

int main(){
    int a, i, j;
    a = 0;
    printf("1000~2000之间所有的素数为：\n");
    for (i = 1000; i <= 2000;i++){
        for (j = 2; j < i;j++){
            if(i%j==0) break;
        }
        if(i==j){
            printf("%d\t", i);
            a++;
            if(a%8==0)
                printf("\n");
        }
    }
    return 0;
}