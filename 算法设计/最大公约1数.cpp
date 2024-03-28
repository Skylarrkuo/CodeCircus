#include <stdio.h>

// ����һ�������������ڱȽ��������Ĵ�С
int max(int a, int b) {
    return (a > b) ? a : b;
}

// �����㷨�ҵ������е����Ԫ��
int findMax(int array[], int start, int end) {
    // �������ֻ��һ��Ԫ�أ���ֱ�ӷ������Ԫ��
    if (start == end) {
        return array[start];
    }
    
    // �ָ�����
    int mid = (start + end) / 2;
    // �ݹ��������������������Ѱ�����ֵ
    int leftMax = findMax(array, start, mid);
    int rightMax = findMax(array, mid + 1, end);
    // �������������������е����ֵ
    return max(leftMax, rightMax);
}

int main() {
    int array[] = {10, 7, 5, 14, 6, 8, 2, 12};
    int n = sizeof(array) / sizeof(array[0]); //�����е�Ԫ�ظ���
    int maxElement = findMax(array, 0, n - 1);
        printf("��������Ϊ:");
    for (int i = 0; i < n;i++){
        printf("%d ", array[i]);
    }
        printf("\n���Ԫ��Ϊ: %d\n", maxElement);
    return 0;
}