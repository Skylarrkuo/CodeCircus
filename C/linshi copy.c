#include <stdio.h>

int main()
{
    int a = 6 ;
    a *= a -= a /= 3;
    printf("%d", a);
}
