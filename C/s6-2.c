#include <stdio.h>
#define L 20 // 定义字符串最大长度
void yuan(char c[L]);
int main()
{
    char c[L];
    printf("输入一个字符串:");
    scanf("%s", &c);
    printf("元音字母有:");
    yuan(c);
    return 0;
}
void yuan(char c[L])
{
    int i, x = 0;
    char t[L];
    for (i = 0; i <= L; i++)
    {
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u')
        {
            t[x++] = c[i];
        }
    }
    t[x] = '\0';
    puts(t);
}