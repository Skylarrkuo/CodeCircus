/*
②最接近数；
【题目描述】
给你个整数数组arr，其中每个元素都不相同。
请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
【输入格式】
输入n个整数，其中每个元素都不相同。
【输出格式】
找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
【输入示例】
3 8 -10 23 19 -4 -14 27
【输出示例】
-14 -10
19 23
23 27
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXNUM 100
using namespace std;

// 函数用于计算数组中最小的元素差值
int MinEDAs(int arr[], int n)
{
    sort(arr, arr + n);    // 对数组进行排序，减少比较次数,系统默认快排
    int minNum = 99999999; // 初始化最小差值为一个较大的数
    for (int i = 0; i < n - 1; i++)
    {
        minNum = min(minNum, abs(arr[i] - arr[i + 1])); // 更新最小差值为相邻元素之差的最小值
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (minNum == abs(arr[i] - arr[i + 1]))
        {
            cout << "[" << arr[i] << "," << arr[i + 1] << "]" << endl;
        } // 比较输出最小差值为相邻元素之差的最小值的数对
    }
    return minNum;
}

int main()
{
    int arr[MAXNUM], n;
    cout << "输入数组大小：";
    cin >> n;
    cout << "输入元素：";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "具有最小绝对差的元素对：" << endl; // 调用函数计算并输出结果
    MinEDAs(arr, n);
    return 0;
}
