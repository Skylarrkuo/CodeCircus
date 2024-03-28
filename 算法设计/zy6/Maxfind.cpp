#include <stdio.h>

// 定义一个辅助函数用于比较两个数的大小
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 分治算法找到数组中的最大元素
int findMax(int array[], int start, int end) {
    // 如果数组只有一个元素，则直接返回这个元素
    if (start == end) {
        return array[start];
    }
    
    // 分割数组
    int mid = (start + end) / 2;
    // 递归地在左右两个子数组中寻找最大值
    int leftMax = findMax(array, start, mid);
    int rightMax = findMax(array, mid + 1, end);
    // 返回左右两个子数组中的最大值
    return max(leftMax, rightMax);
}

int main() {
    int array[] = {10, 7, 5, 14, 6, 8, 2, 12};
    int n = sizeof(array) / sizeof(array[0]); //数组中的元素个数
    int maxElement = findMax(array, 0, n - 1);
        printf("测试数组为:");
    for (int i = 0; i < n;i++){
        printf("%d ", array[i]);
    }
        printf("\n最大元素为: %d\n", maxElement);
    return 0;
}