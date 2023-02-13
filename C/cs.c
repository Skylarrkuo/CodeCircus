#include <stdio.h>
#include <string.h>
#define N 10 // 定义符号变量
char str[N];
void a(char[]);
int main()
{
    // 函数声明
    int i, j;
    for (j = 1; j == 1;)
    // 输入的字符不为10则重新输入
    { 
        printf("请用户输入一个字符串：\n");
        scanf("%s", &str);
        if (strlen(str) > N)
            printf("字符串太长，请用户重新输入");
        else
            j = 0;
    }
    a(str); // 函数调用
    printf("排序后的字符串为：\n");
    for (i = 0; i < N; i++)
        printf("%c", str[i]);
    printf("\n");
    return 0;
}

void a(char str[])
{ // 冒泡法排序函数
    int x, y;
    char t;
    for (y = 1; y < N; y++)
        for (x = 0; (x < N - y) && (str[x] != '\0'); x++)
            if (str[x] > str[x + 1])
            {
                t = str[x];
                str[x] = str[x + 1];
                str[x + 1] = t;
            }
}