#include <stdio.h>

void main(){
    int s[10];
    s[0] = 8;
    s[1] = 9;
    int *p = s;
    *p++;
    printf("%d", *p);

    return 0;
}