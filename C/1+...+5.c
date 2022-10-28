#include <stdio.h>

int main(){
    int i, s;
    s = 0;
    for (i = 1; i <= 5;i++){
        s += i;
    }
    printf("1+2+3+4+5=%d", s);
    return 0;
}