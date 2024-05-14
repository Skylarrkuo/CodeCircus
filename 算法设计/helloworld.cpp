
/*
6
8
0 1 3
0 2 4
1 3 5
1 4 6
2 3 5
2 4 7
3 5 10
4 5 8
*/
#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

// �����
struct Edge {
    int start;
    int end;
    int cost;
};

// ��Сֵ
int min(int x, int y) {
    return (x < y) ? x : y;
}


void dijkstra(int n, int m, int graph[MAX_NODES][MAX_NODES], int source, int destination, int path[MAX_NODES]) {
    int dist[MAX_NODES]; // �洢��Դ�㵽��������·������
    int prev[MAX_NODES]; // �洢���·����ÿ���ڵ��ǰһ���ڵ�
    int i, u, v;

    // ��ʼ�����������ǰ������
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    dist[source] = 0;

    // Dijkstra�㷨
    for (i = 0; i < n; i++) {
        for (u = 0; u < n; u++) {
            for (v = 0; v < n; v++) {
                if (graph[u][v] != INF && dist[u] + graph[u][v] < dist[v] && ((u <= destination && v <= destination) || (u >= source && v >= source))) {
                    dist[v] = dist[u] + graph[u][v];
                    prev[v] = u;
                }
            }
        }
    }

    // �������·��
    int current = destination;
    int count = 0;
    while (current != source) {
        path[count++] = current;
        current = prev[current];
    }
    path[count++] = source;

    // ������·������
    printf("%d [", dist[destination]);

    // ������·�������Ľڵ�
    for (i = count - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf("->");
    }
    printf("]\n");
}

int main() {
    int n, m;
    int graph[MAX_NODES][MAX_NODES];
    struct Edge edges[MAX_NODES];

    // ��ȡͼ�Ľڵ�����ͱ���
    scanf("%d", &n);
    scanf("%d", &m);

    // ��ʼ��ͼ���ڽӾ���
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    // ��ȡ�ߵ���㡢�յ�ʹ���ֵ
    for (int i = 0; i < m; i++) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        graph[start][end] = cost;
    }

    // �ҵ�Դ����յ�
    int source = 0;
    int destination = n - 1;

    // ����Dijkstra�㷨������·��
    int path[MAX_NODES];
    dijkstra(n, m, graph, source, destination, path);

    return 0;
}

