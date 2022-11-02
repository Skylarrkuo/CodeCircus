#include <stdio.h>

int main(){
    char zf;
    int a, b, c, d; //字母，空格，数字，其他字符
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    printf("输入字符，按回车结束:");
    while (zf = getchar())
    {
        if(zf=='\n') break;
        if ((zf >= 'a' && zf <= 'z') || (zf >= 'A' && zf <= 'Z'))
            a++;
        else if (zf == ' ')
            b++;
        else if (zf>=48&&zf<=57)
            c++;
        else
            d++;
    }
    printf("英文字母有：%d\n", a);
    printf("空  格  有：%d\n", b);
    printf("数  字  有：%d\n", c);
    printf("其他字符有：%d\n", d);

    return 0;
}