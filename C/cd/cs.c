#include <stdio.h>
#include <string.h>

int main ()
{
    int x = 1, y = 2, z = 3, flag = 0;
    flag = (x, y, z);
    printf("%d", flag);
    return (0);
}
