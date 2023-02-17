#include <stdio.h>

// 函数cat将字符串2接续在字符串1的尾部，不返回值
void cat(char *str1, char *str2)
{
    // 用while循环找到字符串1的结尾
    while (*str1 != '\0')
    {
        str1++;
    }
    // 用while循环将字符串2中的每个字符复制到字符串1的结尾
    while (*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    // 最后在字符串1的结尾加上'\0'，表示字符串的结束
    *str1 = '\0';
}

int main()
{
    char str1[100], str2[100];
    printf("请输入字符串1：");
    scanf("%s", str1);
    printf("请输入字符串2：");
    scanf("%s", str2);

    // 调用函数cat
    cat(str1, str2);

    printf("连接后的字符串1是：%s\n", str1);

    return 0;
}
