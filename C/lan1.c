#include <stdio.h>
#include <stdlib.h>
int main()
{
    int strLen = 5; //字符串长度，默认设置五个字符
    char ch;        //临时字符变量
    char *str = (char *)malloc(sizeof(char *) * strLen);
    int count = 0; //字符数量+1/ 随输入动态变化
    int t = 1;
    int recount = 0;
    char max;
    //动态输入字符
    do
    {
        ch = getchar();
        count++;
        if (count >= strLen)
        {
            str = (char *)realloc(str, sizeof(char *) * (++strLen));
        }
        str[count - 1] = ch;
    } while (ch != '\n');
    str[count] = '\0';

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (str[i] == str[j] && str[i] != '0')
            {
                t++;
                str[j] = '0';
            }
        }
        if (t > recount)
            {
                recount = t;
                max = str[i];
            }
            t = 1;
    }
    printf("%c\n", max);
    printf("%d", recount);
    return 0;
}