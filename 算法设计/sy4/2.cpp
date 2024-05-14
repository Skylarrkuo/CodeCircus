#include<bits/stdc++.h>
using namespace std;

// 定义常量
const int MAX = 1e2 + 5;
// 定义变量
int n, m, u, v, w, G[MAX][MAX], vis[MAX];
int res = INT_MAX, path[MAX], ans[MAX];

// 深度优先搜索函数
void dfs(int u, int sum, int cnt) {
    // 判断是否找到哈密顿回路
    if(cnt == n && G[u][1]) {
        // 更新最短回路长度和路径
        res = min(res, sum + G[u][1]);
        if(res == sum + G[u][1]) {
            for(int i = 1; i <= n; i++) ans[i] = path[i];
        }
        return;
    }
    // 遍历所有节点
    for(int i = 1; i <= n; i++) {
        if(!vis[i] && G[u][i]) {
            vis[i] = 1;
            path[cnt + 1] = i;
            dfs(i, sum + G[u][i], cnt + 1);
            vis[i] = 0;
        }
    }
}

// 主函数
int main() {
    // 输入节点数和边数
    cin >> n >> m;
    // 输入边的权值
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }
    // 初始化起点
    path[1] = 1;
    vis[1] = 1;
    // 调用深度优先搜索函数
    dfs(1, 0, 1);
    // 输出最短哈密顿回路路径
    for(int i = 1; i <= n; i++) cout << ans[i] << "-->";
    cout << "1" << endl;
    // 输出最短哈密顿回路的长度
    cout << "最短哈密顿回路的长度是：" << res << endl;
    return 0;
}