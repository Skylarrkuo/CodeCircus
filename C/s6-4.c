#include <stdio.h>
#include <string.h>
#define L 20
void mao(char str[10][L]);
int main()
{
    int i, j;
    char str[10][L];
    printf("输入10个字符串:\n");
    for (i = 0; i < 10; i++, j = 0)
    {
        while ((str[i][j] = getchar()) != '\n')
        {
            j++;
        }
        str[i][j] = '\0';
    }
    printf("从小到大排序后为：\n");
    mao(str);
    return 0;
}

void mao(char str[10][L])
{
    int i, j, b;
    char z[L];
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9-i; j++)
        {
            b = strcmp(str[j], str[j + 1]);
            if (b > 0)
            {
                strcpy(z, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], z);
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        puts(str[i]);
    }
}