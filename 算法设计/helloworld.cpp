
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

// 定义边
struct Edge {
    int start;
    int end;
    int cost;
};

// 最小值
int min(int x, int y) {
    return (x < y) ? x : y;
}


void dijkstra(int n, int m, int graph[MAX_NODES][MAX_NODES], int source, int destination, int path[MAX_NODES]) {
    int dist[MAX_NODES]; // 存储从源点到各点的最短路径长度
    int prev[MAX_NODES]; // 存储最短路径中每个节点的前一个节点
    int i, u, v;

    // 初始化距离数组和前驱数组
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    dist[source] = 0;

    // Dijkstra算法
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

    // 构造最短路径
    int current = destination;
    int count = 0;
    while (current != source) {
        path[count++] = current;
        current = prev[current];
    }
    path[count++] = source;

    // 输出最短路径长度
    printf("%d [", dist[destination]);

    // 输出最短路径经过的节点
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

    // 读取图的节点个数和边数
    scanf("%d", &n);
    scanf("%d", &m);

    // 初始化图的邻接矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    // 读取边的起点、终点和代价值
    for (int i = 0; i < m; i++) {
        int start, end, cost;
        scanf("%d %d %d", &start, &end, &cost);
        graph[start][end] = cost;
    }

    // 找到源点和终点
    int source = 0;
    int destination = n - 1;

    // 调用Dijkstra算法求解最短路径
    int path[MAX_NODES];
    dijkstra(n, m, graph, source, destination, path);

    return 0;
}

