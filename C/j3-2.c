#include <stdio.h>

int main()
{
    int a, b, *p1, *p2;
    printf("input a and b:");
    scanf("%d,%d", &a, &b);
    p1 = &a;
    p2 = &b;
    printf("a=%d,b=%d\n", a, b);
    printf("max=%d,min=%d", (*p1 > *p2 ? *p1 : *p2), (*p1 < *p2 ? *p1 : *p2));
    return 0;
}