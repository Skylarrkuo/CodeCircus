#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

// ����ͼ�Ľṹ
struct Edge {
    int to, weight;
};

vector<vector<Edge>> graph;
vector<int> dist;
vector<int> parent;

// �������ȶ��е�Ԫ�ؽṹ
struct Node {
    int vertex, cost;
    bool operator>(const Node& other) const {
        return cost > other.cost;
    }
};

void dijkstra(int source) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({source, 0});
    dist[source] = 0;

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.vertex;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({v, dist[v]});
                parent[v] = u;
            }
        }
    }
}

void printPath(int vertex) {
    if (vertex == -1) return;
    printPath(parent[vertex]);
    cout << vertex << " ";
}

int main() {
    int V = 7; // �������
    graph.resize(V);
    dist.resize(V, INT_MAX);
    parent.resize(V, -1);

    // ����ͼ�ı�
    vector<tuple<int, int, int>> edges = {
        {0, 2, 10}, {0, 4, 30}, {0, 5, 100},
        {1, 2, 4}, {2, 3, 50}, {3, 5, 10},
        {4, 3, 20}, {4, 5, 60}
    };

    for (const auto& edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        graph[u].push_back({v, w});
    }

    int source = 0; // Դ��
    dijkstra(source);

    for (int i = 0; i < V; ++i) {
        if (i == source) continue;
        if (dist[i] == INT_MAX) {
            cout << "��Դ��" << source << "������" << i << "û��·��" << endl;
        } else {
            cout << "��Դ��" << source << "������" << i << "�����·������: " << dist[i] << "��·����";
            printPath(i);
            cout << endl;
        }
    }

    return 0;
}
