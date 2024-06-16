#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 定义边结构体
struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// 定义路径结构体
struct Path {
    int length, last;
    vector<int> nodes;
    Path(int l, int lst, vector<int> n) : length(l), last(lst), nodes(n) {}
    // 重载比较运算符，优先队列需要
    bool operator>(const Path& p) const {
        return length > p.length;
    }
};

// 分支限界法求最短路径
void branchAndBoundShortestPath(vector<vector<Edge>>& graph, int source) {
    priority_queue<Path, vector<Path>, greater<Path>> pq;
    // 从源点开始
    pq.push(Path(0, source, {source}));

    while (!pq.empty()) {
        Path current = pq.top();
        pq.pop();
        int last = current.last;
        // 如果到达新顶点，输出路径和长度
        if (current.nodes.size() > 1) {
            cout << "从源点" << source << "到顶点" << last << "的最短路径长度:" << current.length << "，路径：";
            for (int node : current.nodes) {
                cout << node << " ";
            }
            cout << endl;
        }
        // 遍历所有可达的边
        for (Edge& e : graph[last]) {
            vector<int> new_path(current.nodes);
            new_path.push_back(e.to);
            pq.push(Path(current.length + e.weight, e.to, new_path));
        }
    }
}

int main() {
    // 图的顶点数和边数
    int V, E;
    cin >> V >> E;
    vector<vector<Edge>> graph(V);
    int from, to, weight;
    // 读取边信息
    for (int i = 0; i < E; ++i) {
        cin >> from >> to >> weight;
        graph[from].push_back(Edge(to, weight));
    }

    // 源点
    int source = 0;
    branchAndBoundShortestPath(graph, source);

    return 0;
}
