#include <stdio.h>

int main()
{
    char ch;
    int a, b, c, d;
    a = b = c = d = 0;
    printf("请输入一行字符:");
    while (scanf("%c", &ch))
    {
        if (ch == '\n')
            break;
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
            a++;
        else if (ch >= '0' && ch <= '9')
            b++;
        else if (ch == ' ')
            c++;
    }
    printf("字母%d,数字%d,空格%d,其他%d", a, b, c, d);
    return 0;
}