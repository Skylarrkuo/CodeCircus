#include <stdio.h>

int main()
{
    char a[4]={'a','b','c','\0'};
    int *x;
    x= &a;
    printf("%s", *x);
}