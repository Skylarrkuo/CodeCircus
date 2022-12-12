#include <stdio.h>
void dax(int *p1, int *p2);
int main()
{
    int a, b;
    printf("input a and b:");
    scanf("%d,%d", &a, &b);
    printf("a=%d,b=%d\n", a, b);
    dax(&a, &b);
    return 0;
}
void dax(int *p1, int *p2)
{
    int t;
    if(*p1<*p2){
        t = *p1;
        *p1 = *p2;
        *p2 = t;
    }
    printf("max=%d,min=%d", *p1, *p2);
}