#include <stdio.h>

// ��������������
void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;
    // ���ѭ�����ƱȽ�����
    for (i = 0; i < n-1; i++) {
        // �ڲ�ѭ����ÿһ�������αȽ����ڵ�������
        for (j = 0; j < n-i-1; j++) {
            // ���ǰһ�������ں�һ�������򽻻�����
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
    // �������鳤��
    scanf("%d", &n);
    // �������鲢��������
    float numbers[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &numbers[i]);
    }
    // ����������������������
    bubbleSort(numbers, n);
    // �������������
    for (int i = 0; i < n; i++) {
        printf("%.1f ", numbers[i]);
    }
    return 0;
}