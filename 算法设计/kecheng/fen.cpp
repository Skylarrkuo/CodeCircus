#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 辅助函数，计算跨越中间点的最大子序列和
int maxCrossingSum(const vector<int>& arr, int left, int mid, int right, int& cross_start, int& cross_end) {
    int left_sum = INT_MIN;
    int sum = 0;
    int temp_start = mid;
    
    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        if (sum > left_sum) {
            left_sum = sum;
            temp_start = i;
        }
    }
    
    int right_sum = INT_MIN;
    sum = 0;
    int temp_end = mid + 1;
    
    for (int i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        if (sum > right_sum) {
            right_sum = sum;
            temp_end = i;
        }
    }
    
    cross_start = temp_start;
    cross_end = temp_end;
    return left_sum + right_sum;
}

// 分治法求解最大子序列和
int maxSubArraySum(const vector<int>& arr, int left, int right, int& start, int& end) {
    if (left == right) {
        start = end = left;
        return max(0, arr[left]);
    }
    
    int mid = (left + right) / 2;
    
    int left_start, left_end;
    int right_start, right_end;
    int cross_start, cross_end;
    
    int left_sum = maxSubArraySum(arr, left, mid, left_start, left_end);
    int right_sum = maxSubArraySum(arr, mid + 1, right, right_start, right_end);
    int cross_sum = maxCrossingSum(arr, left, mid, right, cross_start, cross_end);
    
    if (left_sum >= right_sum && left_sum >= cross_sum) {
        start = left_start;
        end = left_end;
        return left_sum;
    }
    else if (right_sum >= left_sum && right_sum >= cross_sum) {
        start = right_start;
        end = right_end;
        return right_sum;
    }
    else {
        start = cross_start;
        end = cross_end;
        return cross_sum;
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int start, end;
    int max_sum = maxSubArraySum(arr, 0, N - 1, start, end);

    cout << max_sum << endl;
    if (max_sum > 0) {
        for (int i = start; i <= end; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
