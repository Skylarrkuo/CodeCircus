#include <stdio.h>

unsigned long long pow_X(int n)
{
    if (n == 0)
        return 1;
    return pow_X(--n) * 16;
}
int main()
{
    unsigned long long sum = 0,i = 0, j = 0, n = 0;
    char ch[10];
    gets(ch);
    do
    {
        i++;
    } while (ch[i - 1] != '\0');
    i--;
    i--;
    n = i;
    for (j = 0; j <= n; j++)
    {
        if (ch[j] < 65)
            sum = sum + (unsigned long long)(ch[j] - 48) * pow_X(i);
        else
            sum = sum + (unsigned long long)(ch[j] - 55) * pow_X(i);
        i--;
    }
    printf("%lld", sum);
    return 0;
}