#include <stdio.h>
int main()
{
    int a = 3, b,c;
    b = (a++) + (a++) + (a++);
    printf("%d\t", a);
    printf("%d,%d\n", a, b);
    c = (++a) + (++a) + (++a);
    printf("%d,%d\n",c,a);
    return 0;
}