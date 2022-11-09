#include <stdio.h>

int main(){
    int s, i;
    s = 1;
    for (i = 1; i < 10;i++){
        s = (s + 1) * 2;
    }
    printf("原来的桃子有：%d个", s);
    return 0;
}