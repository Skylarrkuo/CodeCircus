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

    int max_sum = 0;  // 最大子序列和
    int start = 0;    // 最大子序列的开始位置
    int end = 0;      // 最大子序列的结束位置

    // 枚举所有可能的子序列
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

    // 输出结果
    cout << max_sum << endl;
    for (int i = start; i <= end; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
