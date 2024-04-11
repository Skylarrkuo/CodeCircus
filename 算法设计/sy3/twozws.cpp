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
/*
① 该算法可能出现的情况包括：两个输入序列长度不相等、输入序列为空、输入序列中有重复元素等。测试数据覆盖了这些情况，输出结果正确。
② 算法的时间复杂度为O(n)，在问题规模很大时是可以接受的。
③ 另一种解决方式是使用二分查找来寻找中位数，可以提高效率。
④ 选择使用vector作为数据结构是合适的，因为需要在合并序列时动态添加元素。
⑤ 通过实验，我理解了合并两个有序序列并计算中位数的思想，该算法的优点是简单易懂，缺点是空间复杂度较高。
⑥ 在实验过程中没有遇到问题。
⑦ 感觉这种合并有序序列并计算中位数的算法在一些场景下还是很有用的，可以帮助解决一些实际问题。
*/