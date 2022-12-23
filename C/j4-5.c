#include <stdio.h>
int lengther(char *a[]);
int main()
{
    char a[100]; // 声明一个长度为100的数组存储字符串
    int i = 0, c;
    printf("输入字符串:");
    while ((a[i] = getchar()) != '\n' && i <= 100) // 循环输出字符串，回车截止
    {
        i++;
    }
    a[i] = '\0';                           // 为输入的最后一个字符赋值‘\0’表示字符串结尾
    c = lengther(&a[0]);                   // 调用函数计算长度，传递字符串数组的起始地址，由c进行存储
    printf("字符串 %s 的长度为:%d", a, c); // 输出字符串长度
    return 0;
}
int lengther(char *a[]) // 接收字符串数组起始地址
{
    int i = 0;
    while (*a != '\0') // 对起始地址的第一个字符进行判断，后续直到判断到'\0'退出循环
    {
        a += 1; // char类型占1字节，对地址+1跳到下一个字符
        i++;    // 长度+1
    }
    return i;
}