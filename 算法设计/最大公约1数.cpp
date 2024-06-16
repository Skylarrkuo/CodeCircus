
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

void shortestPath(vector<Edge>& edges, int V, int E, int source) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (i != source) {
            if (dist[i] == INT_MAX) {
                cout << "从源点" << source << "到顶点" << i << "没有路径" << endl;
            } else {
                cout << "从源点" << source << "到顶点" << i << "的最短路径长度:" << dist[i] << endl;
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int source;
    cin >> source;

    shortestPath(edges, V, E, source);

    return 0;
}
