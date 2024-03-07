#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXNUM 100
using namespace std;

// 函数用于计算数组中最小的元素差值
int MinED(int arr[], int n)
{
    sort(arr, arr + n); // 对数组进行排序，减少比较次数
    int ED = 99999999; // 初始化最小差值为一个较大的数
    for (int i = 0; i < n - 1; i++)
    {
        ED = min(ED, abs(arr[i] - arr[i+1])); // 更新最小差值为相邻元素之差的最小值
    }
    return ED;
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
    cout << "数组中最小的元素差为：" << MinED(arr, n); // 调用函数计算并输出结果
    return 0;
}
