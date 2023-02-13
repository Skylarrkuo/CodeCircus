#include <stdio.h>

int main()
{
    int i, j = 0;
    char str1[100], str2[80];//声明两个数组
    //分别输入两个字符串
    gets(str1);
    gets(str2);
    //对第一个数组进行遍历
    for (i = 0; i < 100; i++)
    {
        //到字符串结尾标识停止
        if (str1[i] == '\0')
        {
            //在此位置对数组进行连接
            while (i)
            {
                str1[i++] = str2[j];
                if (str1[j++] == '\0') break;
            }
            if (str1[i] == '\0') break;
        }
    }
    //输出连接后的字符串
    puts(str1);
}