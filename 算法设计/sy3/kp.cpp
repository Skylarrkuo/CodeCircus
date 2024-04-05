#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ��������
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int i = low, j = high, pivot = arr[low]; // ���û�׼Ԫ��Ϊ���еĵ�һ��Ԫ��
        while (i < j) {
            // ���������ҵ���һ��С�ڻ�׼Ԫ�ص�Ԫ��
            while (i < j && arr[j] >= pivot) {
                j--;
            }
            if (i < j) {
                arr[i++] = arr[j]; // ����Ԫ���Ƶ���׼Ԫ�ص����
            }
            // ���������ҵ���һ�����ڻ���ڻ�׼Ԫ�ص�Ԫ��
            while (i < j && arr[i] < pivot) {
                i++;
            }
            if (i < j) {
                arr[j--] = arr[i]; // ����Ԫ���Ƶ���׼Ԫ�ص��ұ�
            }
        }
        arr[i] = pivot; // ����׼Ԫ�طŵ�����λ��
        // �ݹ������׼Ԫ������������
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

    quickSort(arr, 0, n - 1); // ���ÿ���������

    // �������������
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}