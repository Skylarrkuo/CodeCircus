#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 快速排序
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int i = low, j = high, pivot = arr[low]; // 设置基准元素为序列的第一个元素
        while (i < j) {
            // 从右向左找到第一个小于基准元素的元素
            while (i < j && arr[j] >= pivot) {
                j--;
            }
            if (i < j) {
                arr[i++] = arr[j]; // 将该元素移到基准元素的左边
            }
            // 从左向右找到第一个大于或等于基准元素的元素
            while (i < j && arr[i] < pivot) {
                i++;
            }
            if (i < j) {
                arr[j--] = arr[i]; // 将该元素移到基准元素的右边
            }
        }
        arr[i] = pivot; // 将基准元素放到相遇位置
        // 递归排序基准元素左右两部分
        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1); // 调用快速排序函数

    // 输出排序后的序列
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
算法: 快速排序

输入: 一个数组 nums，数组的起始索引 left，数组的结束索引 right

输出: 经过快速排序后的数组 nums

1. 如果 left 大于等于 right，则返回
2. 选择基准值 pivot 为 nums[left]
3. 初始化两个指针 l = left, r = right
4. 当 l < r 时循环：
   - 从右向左找到第一个小于 pivot 的元素，并赋值给 nums[l]
   - 从左向右找到第一个大于 pivot 的元素，并赋值给 nums[r]
   - 重复上述步骤直到 l >= r
5. 将基准值 pivot 放到最终位置 nums[l]
6. 递归调用快速排序处理左边部分：quickSort(nums, left, l - 1)
7. 递归调用快速排序处理右边部分：quickSort(nums, l + 1, right)
*/