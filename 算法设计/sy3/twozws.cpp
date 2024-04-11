#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMedian(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<int> merged;
    int i = 0, j = 0;

    // 合并两个有序序列
    while (i < n && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            merged.push_back(nums1[i]);
            i++;
        }
        else
        {
            merged.push_back(nums2[j]);
            j++;
        }
    }
    while (i < n)
    {
        merged.push_back(nums1[i]);
        i++;
    }
    while (j < n)
    {
        merged.push_back(nums2[j]);
        j++;
    }

    // 计算合并后序列的中位数
    int m = merged.size();
    if (m % 2 == 0)
    {
        return (merged[m / 2 - 1] + merged[m / 2]) / 2;
    }
    else
    {
        return merged[m / 2];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    // 调用函数找出两个序列的中位数并输出
    cout << findMedian(A, B) << endl;

    return 0;
}
/*
算法: 查找两个有序序列的中位数
输入: 两个有序序列 nums1 和 nums2
输出: 两个有序序列的中位数

1. 初始化变量 n 为 nums1 的长度，merged 为空数组，i 和 j 初始化为 0
2. while 循环合并两个有序序列 nums1 和 nums2：
   2.1 如果 nums1[i] <= nums2[j]，则将 nums1[i] 添加到 merged 中，i 自增
   2.2 否则，将 nums2[j] 添加到 merged 中，j 自增
3. 将 nums1 或 nums2 中剩余的元素添加到 merged 中
4. 计算合并后序列 merged 的长度 m
5. 如果 m 为偶数，则返回 (merged[m / 2 - 1] + merged[m / 2]) / 2 作为中位数
6. 否则，返回 merged[m / 2] 作为中位数
*/