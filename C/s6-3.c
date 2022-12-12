#include <stdio.h>
#define L 100
void ch(char t[L]);
int a = 0, b = 0, c = 0, d = 0;
int main()
{
    int i = 0;
    char t[L];
    printf("输入字符串:");
    while ((t[i] = getchar()) != '\n')
        i++;
    t[i] = '\0';
    ch(t);
    printf("字母有:%d\n空格有:%d\n数字有:%d\n其他有:%d", a, b, c, d);
    return 0;
}
void ch(char t[])
{
    int i;
    for (i = 0; t[i] != '\0'; i++)
    {
        if ((t[i] >= 'A' && t[i] <= 'Z') || (t[i] >= 'a' && t[i] <= 'z'))
            a++;
        else if (t[i] == ' ')
            b++;
        else if (t[i] >= '0' && t[i] <= '9')
            c++;
        else
            d++;
    }
}