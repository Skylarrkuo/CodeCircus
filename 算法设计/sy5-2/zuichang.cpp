#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 动态规划求解编辑距离
int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    
    // 创建二维数组dp，dp[i][j]表示将word1的前i个字符变成word2的前j个字符所需的最小操作步数
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // 初始化第一行和第一列
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i; // 将一个字符串变为空字符串需要的步数为其长度
    }
    
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j; // 将一个空字符串变成另一个字符串需要的步数为其长度
    }
    
    // 动态规划求解编辑距离
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1]; // 如果当前字符相同，则无需操作
            } else {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])); // 当前字符不同，取三种操作的最小值+1
            }
        }
    }
    
    return dp[m][n]; // 返回将word1变成word2所需的最小操作步数
}

int main() {
    string word1, word2;
    
    // 循环读入测试数据并输出结果
    while (cin >> word1 >> word2) {
        int distance = minDistance(word1, word2);
        cout << distance << endl;
    }
    
    return 0;
}
