#include <stdio.h>

int main(){
    int a, b, c, i;
    for (i = 1; i <= 4;i++){
        for (b = 1; b <= i * 2 - 1;b++)
        {
            printf(" ");
        }
        for (a = 1; a <= 8 - (i*2-1); a++){
            c = 10 - i;
            printf("%d ", c);
        }
        printf("\n");
    }
    return 0;
}