#include <stdio.h>

// 定义起泡排序函数
void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;
    // 外层循环控制比较轮数
    for (i = 0; i < n-1; i++) {
        // 内层循环在每一轮中依次比较相邻的两个数
        for (j = 0; j < n-i-1; j++) {
            // 如果前一个数大于后一个数，则交换它们
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    // 输入数组长度
    scanf("%d", &n);
    // 定义数组并输入数据
    float numbers[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &numbers[i]);
    }
    // 调用起泡排序函数进行排序
    bubbleSort(numbers, n);
    // 输出排序后的数组
    for (int i = 0; i < n; i++) {
        printf("%.1f ", numbers[i]);
    }
    return 0;
}