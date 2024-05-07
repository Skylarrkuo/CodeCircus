#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, cost;
};

// 定义比较函数用于排序边
bool cmp(const Edge &a, const Edge &b) {
    return a.cost < b.cost;
}

// 查找根节点的函数
int find(vector<int> &parent, int x) {
    return parent[x] == x ? x : parent[x] = find(parent, parent[x]);
}

// 合并两个节点的函数
void unite(vector<int> &parent, int x, int y) {
    parent[find(parent, x)] = find(parent, y);
}

// Kruskal算法求最小生成树
int kruskal(vector<Edge> &edges, int n) {
    // 按照边的权值进行排序
    sort(edges.begin(), edges.end(), cmp);
    // 初始化并查集
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int totalCost = 0;
    // 遍历每条边
    for (int i = 0; i < edges.size(); i++) {
        Edge e = edges[i];
        // 如果两个节点不在同一个连通分量中，将它们合并，并加上边的权值
        if (find(parent, e.u) != find(parent, e.v)) {
            unite(parent, e.u, e.v);
            totalCost += e.cost;
        }
    }
    // 判断是否所有节点都在同一个连通分量中
    int root = find(parent, 1);
    for (int i = 2; i <= n; i++) {
        if (find(parent, i) != root) {
            return -1; // 如果不在同一个连通分量中，返回-1
        }
    }
    return totalCost;
}

int main() {
    int N, M;
    while (cin >> N >> M && N > 0 && M > 0) {
        vector<Edge> edges(N);
        // 读入每条边的信息
        for (int i = 0; i < N; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].cost;
        }
        // 调用Kruskal算法求解最小生成树的总权值
        int result = kruskal(edges, M);
        if (result == -1) {
            cout << "?" << endl;
        } else {
            cout << result << endl;
        }
    }
    return 0;
}