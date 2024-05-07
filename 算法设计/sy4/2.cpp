#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e2 + 5;
int n, m, u, v, w, G[MAX][MAX], vis[MAX];
int res = INT_MAX, path[MAX], ans[MAX];

void dfs(int u, int sum, int cnt) {
    if(cnt == n && G[u][1]) {
        res = min(res, sum + G[u][1]);
        if(res == sum + G[u][1]) {
            for(int i = 1; i <= n; i++) ans[i] = path[i];
        }
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i] && G[u][i]) {
            vis[i] = 1;
            path[cnt + 1] = i;
            dfs(i, sum + G[u][i], cnt + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }
    path[1] = 1;
    vis[1] = 1;
    dfs(1, 0, 1);
    for(int i = 1; i <= n; i++) cout << ans[i] << "-->";
    cout << "1" << endl;
    cout << "最短哈密顿回路的长度是：" << res << endl;
    return 0;
}
