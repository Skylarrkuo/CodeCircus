#include <stdio.h>

int main(){
    long long int i, j, m, s;
    s = 0;
    for (i = 1; i <= 20;i++){
        m = 1;
        for (j = 1; j <= i;j++){
            m *= j;
        }
        s += m;
    }
    printf("1!+2!+...+20!=%lld", s);
}