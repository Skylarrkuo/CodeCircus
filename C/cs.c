#include <stdio.h>
int a, b, c, d;
void co(char str[]);
int main()
{
    char x[80];
    printf("请用户输入一个字符串：");
    gets(x);
    printf("string:");
    puts(x);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    co(x);
    printf("a:%d\nb:%d\nc:%d\nd:%d\n", a, b, c, d);
    return 0;
}

void co(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            a++;
        else if (str[i] >= '0' || str[i] <= '9')
            b++;
        else if (str[i] == ' ')
            c++;
        else
            d++;
}