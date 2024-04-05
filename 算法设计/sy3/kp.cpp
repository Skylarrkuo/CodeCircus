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