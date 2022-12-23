#include <stdio.h>
void counter(char x[80]);
int a, b, c, d; // 声明用于存储字符串中字符类别的全局变量
int main()
{
    char x[80];
    int i = 0;
    while ((x[i] = getchar()) != '\n' && i <= 80) // 循环输入字符串
    {
        i++;
    }
    x[i] = '\0'; // 对输入的最后一个位置赋值为'\0'表示字符串结尾
    counter(x);
    printf("字母有%d个\n", a);
    printf("数字有%d个\n", b);
    printf("空格有%d个\n", c);
    printf("其他字符有%d个", d);
    return (0);
}
void counter(char x[80])
{
    int i;
    a = 0, b = 0, c = 0, d = 0;//对各类型全局变量赋初值
    for (i = 0; x[i] != '\0'; i++) // 挨个对每个字符进行判断，截止到字符串结尾
    {
        if (x[i] >= 'a' && x[i] <= 'z' || x[i] >= 'A' && x[i] <= 'Z')
            a++;
        else if (x[i] >= '0' && x[i] <= '9')
            b++;
        else if (x[i] == ' ')
            c++;
        else
            d++;
    }
}