#include <stdio.h>
#include <math.h>
int main()
{
    int i;
    long x = 1194684, y=0;
    for (i = 0; x / 8 != 0; i++)
    {
        y += (x % 8) * pow(10, i);
        x /= 8;
    }
    y += x  * pow(10, i);
    printf("%d", y);
    return 0;
}