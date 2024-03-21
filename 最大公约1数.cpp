/*
①欧几里得算法；
【题目描述】
输入两个正整数，求其最大公约数。
【输入格式】
测试数据有多组，每组输入两个正整数。
【输出格式】
对于每组输入,请输出其最大公约数。
【输入示例】
49 14
48 36
【输出示例】
7
12
*/
#include <iostream>
using namespace std;
int gcd(int &a, int &b)
{ // 欧几里得算法计算公约数
    int r, t;
    if (a < b) // 始终使a>b
    {
        t = a;
        a = b;
        b = t;
    }
    r = a % b;//首次相除取余数
    
    if (r == 0)
    {//如果a可以被b整除则b为最大公约数
        a = b;
        return 0;
    }
    while (r != 0)
    {//辗转相除直到余数为0
        r = a % b;
        a = b;
        b = r;
    }
}
int main()
{
    for (int x, y; cin >> x >> y;) // 输入多组数据，为空时结束
    {
        gcd(x, y); // 调用欧几里得算法求最大公约数
        cout <<  x << endl;
    }
    return 0;
}
