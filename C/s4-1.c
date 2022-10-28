#include <stdio.h>

int main(){
    int i, n, sum;
    sum = 0;
    printf("ipnut n:");
    scanf("%d", &n);
    for (i = 1; i <= n;i++){
        sum += i * (i + 1);
    }
    printf("sum=%d", sum);
    return 0;
}