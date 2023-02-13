#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, l;
    char a[8];
    unsigned long long int x = 0;
    gets(a);
    for (l = 0; a[i] != '\0'; l++,i++);
    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
            x += (a[i] - '0') * pow(16, --l);
        else if (a[i] >= 'A' && a[i] <= 'F')
            x += (a[i] - 55) * pow(16, --l);
    }
    printf("%lld\n", x);
    return 0;
}