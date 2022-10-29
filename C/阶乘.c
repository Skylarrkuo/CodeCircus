#include <stdio.h>
//1~5½×³Ë
int main(){
    int i, s,j,a;
    s = 0;
    for (i = 1; i <= 5;i++){
        a = 1;
        for (j = 1; j <= i;j++){
            a *= j;
        }
        s += a;
    }
    printf("1+2+3+4+5=%d", s);
}