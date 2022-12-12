#include <stdio.h>
int main()
{
    int x, *p;
    printf("input x:");
    scanf("%d", &x);
    p = &x;
    printf("x=%d,*p=%d", x, *p);
    return 0;
}