#include <stdio.h>

int main(){
    int a = 0, b = 0;
    double c = 0, s = 0;
    int i;
    for (i = 1; i <= 100;i++){
        a += i;
        if(i<=50)
            b += i * i;
        if(i<=10)
            c += 1.0 / i;
    }
    s = a + b + c;
    printf("a+b+c=%llf", s);
    return 0;
}