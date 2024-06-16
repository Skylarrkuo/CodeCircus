#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// ����߽ṹ��
struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// ����·���ṹ��
struct Path {
    int length, last;
    vector<int> nodes;
    Path(int l, int lst, vector<int> n) : length(l), last(lst), nodes(n) {}
    // ���رȽ�����������ȶ�����Ҫ
    bool operator>(const Path& p) const {
        return length > p.length;
    }
};

// ��֧�޽編�����·��
void branchAndBoundShortestPath(vector<vector<Edge>>& graph, int source) {
    priority_queue<Path, vector<Path>, greater<Path>> pq;
    // ��Դ�㿪ʼ
    pq.push(Path(0, source, {source}));

    while (!pq.empty()) {
        Path current = pq.top();
        pq.pop();
        int last = current.last;
        // ��������¶��㣬���·���ͳ���
        if (current.nodes.size() > 1) {
            cout << "��Դ��" << source << "������" << last << "�����·������:" << current.length << "��·����";
            for (int node : current.nodes) {
                cout << node << " ";
            }
            cout << endl;
        }
        // �������пɴ�ı�
        for (Edge& e : graph[last]) {
            vector<int> new_path(current.nodes);
            new_path.push_back(e.to);
            pq.push(Path(current.length + e.weight, e.to, new_path));
        }
    }
}

int main() {
    // ͼ�Ķ������ͱ���
    int V, E;
    cin >> V >> E;
    vector<vector<Edge>> graph(V);
    int from, to, weight;
    // ��ȡ����Ϣ
    for (int i = 0; i < E; ++i) {
        cin >> from >> to >> weight;
        graph[from].push_back(Edge(to, weight));
    }

    // Դ��
    int source = 0;
    branchAndBoundShortestPath(graph, source);

    return 0;
}
