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
int gcd(int &x, int &y)
{
    int r, t;
    if (x < y)
    {
        t = x;
        x = y;
        y = t;
    }
    r = 1;
    while (r != 0)
    {
        x = y;
        y = x%y;
        r = y;
    }
}

int main()
{
    for (int x, y; cin >> x >> y;) // 输入多组数据，为空时结束
    {
        gcd(x, y); // 调用欧几里得算法求最大公约数
        cout << "gcb=" << y << endl;
    }
    return 0;
}
