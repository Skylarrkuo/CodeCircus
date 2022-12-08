#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hfjc(int year, int month, int day); //定义用于检测输入日期合法性的函数
int main()
{
    //定义存储日期合法性的变量（1为合法，0为不合法）
    int h;
    //定义用于存储年月日的变量
    int year = 1949;
    int month = 10;
    int day = 2;
    //定义存储日期个数的变量
    int s = 0;
    int j = 0;
    for (; year <= 2022; year++)
    {
        for (; month <= 12; month++)
        {
            for (; day <= 31; day++)
            {
                if (hfjc(year, month, day))
                {
                    s++;
                    if ((year * 10000 + month * 100 + day) == 20220101)
                    {
                        j = 1;
                        break;
                    }
                }
            }
            day = 1;
            if (j == 1)
                break;
        }
        month = 1;
        if (j == 1)
            break;
    }
    printf("%d", s);
    return 0;
}
//输入日期合法性判断函数
int hfjc(int year, int month, int day)
{
    int h;
    if (month < 1 || month > 12)
    {
        h = 0;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day >= 1 && day <= 31)
        {
            h = 1;
        }
        else
        {
            h = 0;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day >= 1 && day <= 30)
        {
            h = 1;
        }
        else
        {
            h = 0;
        }
    } //前面已经判断了是否为大月或者小月，仅剩下二月份，还需要判断是否为闰年。
    else if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
    {
        if (day >= 1 && day <= 29)
        {
            h = 1;
        }
        else
        {
            h = 0;
        }
    }
    else
    {
        if (day >= 1 && day <= 28)
        {
            h = 1;
        }
        else
        {
            h = 0;
        }
    }
    return h;
}