#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 7 // 图中顶点的数量，包括未直接连接的顶点

// 找到最小距离顶点的函数
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// 打印路径的函数
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf(" %d", j);
}

// 打印解决方案的函数
void printSolution(int dist[], int parent[], int n) {
    int src = 0;
    printf("Vertex\t Distance\tPath");
    for (int i = 1; i < V; i++) {
        if (i != src) {
            printf("\n%d -> %d \t ", src, i);
            if (dist[i] == INT_MAX) {
                printf("没有路径");
            } else {
                printf("%d\t\t%d", dist[i], src);
                printPath(parent, i);
            }
        }
    }
}

// Dijkstra算法的实现
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // 从源点到i的最小距离
    int sptSet[V]; // 是否已经在最短路径树中
    int parent[V]; // 最短路径树的父节点数组

    // 初始化所有距离为无穷大，sptSet[]为false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0, parent[i] = -1;

    // 源点到自己的距离总是0
    dist[src] = 0;

    // 找出所有顶点的最短路径
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        // 标记顶点u为已处理
        sptSet[u] = 1;

        // 更新顶点u的邻接顶点的距离
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    // 打印最短路径和距离
    printSolution(dist, parent, V);
}

int main() {
    // 创建一个图的邻接矩阵
    int graph[V][V] = {{0}};
    
    // 读取边的信息
    int u, v, w;
    while (scanf("%d %d %d", &u, &v, &w) != EOF) {
        graph[u][v] = w;
    }

    // 调用dijkstra算法
    dijkstra(graph, 0);

    return 0;
}
