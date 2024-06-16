#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 求最大连续子序列和的函数
pair<int, vector<int>> maxSubsequenceSum(const vector<int>& A) {
    int N = A.size();
    if (N == 0) {
        return {0, {}};
    }
    // 动态规划数组
    vector<int> dp(N);
    dp[0] = A[0];
    int max_sum = dp[0];
    int start = 0, end = 0, temp_start = 0;
    for (int i = 1; i < N; ++i) {
        if (dp[i-1] + A[i] > A[i]) {
            dp[i] = dp[i-1] + A[i];
        } else {
            dp[i] = A[i];
            temp_start = i;
        }
        // 更新最大和
        if (dp[i] > max_sum) {
            max_sum = dp[i];
            start = temp_start;
            end = i;
        }
    }
    // 获取最大子序列
    vector<int> max_subsequence(A.begin() + start, A.begin() + end + 1);
    // 返回最大和和最大子序列
    return {max_sum, max_subsequence};
}
int main() {
    // 输入
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    // 求解
    pair<int, vector<int>> result = maxSubsequenceSum(A);
    // 输出
    cout << result.first << endl;
    for (int i : result.second) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
