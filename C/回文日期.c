#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hfjc(int year, int month, int day); //定义用于检测输入日期合法性的函数
int zhuan(int x, int y);                //定义用于将日期中的月日即mmdd反转为ddmm的函数(例如1212转为2121)
int main()
{
    //定期存储日期的字符
    // yyyy
    // mm
    // dd
    char y1, y2, y3, y4;
    char m1, m2;
    char d1, d2;
    //定义存储日期合法性的变量（1为合法，0为不合法）
    int h;
    //分块输入字符
    scanf("%c%c%c%c%c%c%c%c", &y1, &y2, &y3, &y4, &m1, &m2, &d1, &d2);
    //定义用于存储年月日的变量，并将年月日各部分转为整形存储
    int year = (y1 - '0') * 1000 + (y2 - '0') * 100 + (y3 - '0') * 10 + (y4 - '0');
    int month = (m1 - '0') * 10 + (m2 - '0');
    int day = (d1 - '0') * 10 + (d2 - '0');
    //定义存储输出日期个数的变量，输出个数达到2时不再循环
    int s;
    s = 0;
    //首先对输入日期的合法性进行判断，调用判断函数
    h = hfjc(year, month, day);
    //如果为合法则开始执行寻找回文日期的操作
    if (h == 1)
    {
        for (; year <= 8999; year++)
        {
            for (; month <= 12; month++)
            {
                for (day++; day <= 31; day++)
                {
                    if (hfjc(year, month, day))
                    {
                        //判断是否为回文日期
                        if (year == zhuan(month, day) && s != 1) //输出个数为1时不在判断回文日期
                        {
                            printf("%ld\n", year * 10000 + month * 100 + day);
                            s++;
                            break;
                        }
                        //判断是否为ABABBABA型日期
                        if (year == zhuan(month, day) && (year % 100 == year / 100) && (zhuan(month, day) % 100 == zhuan(month, day) / 100) && year % 100 == zhuan(month, day) % 100)
                        {
                            printf("%ld\n", year * 10000 + month * 100 + day);
                            s++;
                            break;
                        }
                    }
                }
                if (s == 2)
                    break;
                day = 1;
            }
            if (s == 2)
                break;
            month = 1;
        }
    }
    return 0;
}
//字符转换函数
int zhuan(int x, int y)
{

    return (y / 10 + (y % 10) * 10) * 100 + (x / 10 + (x % 10) * 10);
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