#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
    if(num <= 1) {
        return false;
    }
    for(int i = 2; i*i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

void printVector(const vector<int>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void backtracking(int n, vector<int>& arr, vector<bool>& used, int index) {
    if(index == n) {
        if(isPrime(arr[0] + arr[n-1])) {
            printVector(arr);
        }
    } else {
        for(int i = 2; i <= n; i++) {
            if(!used[i]) {
                if(isPrime(i + arr[index-1])) {
                    arr[index] = i;
                    used[i] = true;
                    backtracking(n, arr, used, index+1);
                    used[i] = false;
                }
            }
        }
    }
}

int main() {
    int n;
    while(cin >> n && n != 0) {
        vector<int> arr(n);
        vector<bool> used(n+1, false);
        arr[0] = 1;
        used[1] = true;
        cout << n << "个数的素数环:" << endl;
        backtracking(n, arr, used, 1);
        if(n > 1 && n % 2 == 1) {
            cout << "No Circle" << endl;
        }
    }
    return 0;
}
