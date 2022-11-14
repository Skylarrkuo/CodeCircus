#include <math.h>
#include <stdio.h>

int main()
{
    int i, j;
    for (i = -3; i <= 3; i++)
    {
        for (j = 1; j <= fabs(i); j++)
        {
            printf(" ");
        }
        for (j = 1; j <= 7 - fabs(i) * 2; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}