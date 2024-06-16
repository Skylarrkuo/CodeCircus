#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int max_sum = 0;  // ��������к�
    int start = 0;    // ��������еĿ�ʼλ��
    int end = 0;      // ��������еĽ���λ��

    // ö�����п��ܵ�������
    for (int i = 0; i < N; ++i) {
        int current_sum = 0;
        for (int j = i; j < N; ++j) {
            current_sum += A[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
                start = i;
                end = j;
            }
        }
    }

    // ������
    cout << max_sum << endl;
    for (int i = start; i <= end; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
