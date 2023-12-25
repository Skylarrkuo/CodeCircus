/*1．使用邻接矩阵或者邻接表创建一个如下所示的无向图,并采用深度优先搜索
和广度优先搜索 2 种遍历算法对图进行遍历.*/
#include <iostream>
using namespace std;

#define OK 1;
#define MVNum 100
#define MaxInt 32767
#define MAXSIZE 100
#define ERROR 0
typedef int VerTex;
typedef char VerTexType;
typedef int ArcTypr;
typedef int Status;

//=====队列===========
typedef struct{
    VerTex date;
} QElemType;

typedef struct{
    QElemType *base;
    int front;
    int rear;
} SqQueue;

Status InitQueue(SqQueue &Q){
    // 初始化队列
    Q.base = new QElemType[MAXSIZE];
    if (!Q.base)
        return ERROR;
    Q.front = 0;
    Q.rear = 0;
    return OK;
}

Status DestroyQueue(SqQueue &Q){
    // 销毁队列
    if (!Q.base)
        return ERROR;
    delete[] Q.base;
    Q.front = Q.rear = 0;
    return OK;
}

Status QueueEmpty(SqQueue Q){
    // 队列判空
    if (!Q.base)
        return ERROR;
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

Status EnQueue(SqQueue &Q, QElemType &e){
    // 入队
    if (!Q.base)
        return ERROR;
    Q.base[Q.rear % MAXSIZE] = e;
    Q.rear++;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e){
    // 出队
    if (!Q.base)
        return ERROR;
    e = Q.base[Q.front];
    Q.front++;
    return 0;
}

//===邻接矩阵=================================
// 邻接矩阵无向图存储结构
typedef struct{
    bool visited[MVNum];
    VerTexType vexs[MVNum];
    ArcTypr arcs[MVNum][MVNum];
    int vexnum = 0, arcnum = 0;
} AMGraph;

// 邻接矩阵的查找顶点位置
Status LocateVex(AMGraph G, VerTexType v){
    int k;
    for (k = 1; k <= G.vexnum; k++)
    {
        if (G.vexs[k] == v)
            break;
    }
    if (k > G.vexnum)
        return -1;
    return k;
}

// 构造邻接矩阵无向图
Status CreateUDN(AMGraph &G){
    char v1, v2;
    int i, j, k, w;
    cout << "输入无向图的顶点数个数和边数,用空格隔开:";
    cin >> G.vexnum >> G.arcnum;
    cout << "输入" << G.vexnum << "个顶点:";
    for (k = 1; k <= G.arcnum; k++){
        cin >> G.vexs[k];
    }
    // 构造邻接矩阵
    for (i = 1; i <= G.vexnum; i++){
        for (j = 1; j <= G.vexnum; j++){
            G.arcs[i][j] = MaxInt;
        }
    }

    for (k = 1; k <= G.arcnum; k++){
        cout << "输入第" << k << "条边依附的的顶点及权值:";
        cin >> v1 >> v2 >> w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = w;
    }
    return OK;
}

// 输出邻接矩阵无向图
Status InputAMGraph(AMGraph G){
    int i, j, k;
    cout << "邻接矩阵无向图的顶点有:" << endl;
    for (k = 1; k <= G.vexnum; k++){
        printf("%c ", G.vexs[k]);
    }
    cout << endl;
    cout << "邻接矩阵位:" << endl;
    for (i = 1; i <= G.vexnum; i++){
        printf("|");
        for (j = 1; j <= G.vexnum; j++){
            printf("%d\t", G.arcs[i][j]);
        }
        printf("|\n");
    }
    return OK;
}
// 清空邻接表顶点访问标志
Status ClearAMvisited(AMGraph &G){
    for (int i = 0; i <= G.vexnum; i++){
        G.visited[i] = false;
    }
    return OK;
}
// 邻接矩阵深度优先遍历(递归)
Status DFS_AM(AMGraph &G, int v){
    // G为邻接矩阵,从第v个顶点出深度优先搜索遍历
    cout << G.vexs[v];
    G.visited[v] = true;
    for (int w = 0; w <= G.vexnum; w++){
        if ((G.arcs[v][w] != MaxInt) && (!G.visited[w]))
            DFS_AM(G, w);
    }
    return OK;
}

// 邻接矩阵广度优先遍历
Status BFS_AM(AMGraph G, int v){
    SqQueue Q;           // 创建一个队列Q
    InitQueue(Q);        // 初始化队列Q
    cout << G.vexs[v];   // 输出起始顶点的数据元素
    G.visited[v] = true; // 标记起始顶点为已访问
    QElemType e;
    e.date = v;
    EnQueue(Q, e);         // 起始顶点入队
    while (!QueueEmpty(Q)){ // 循环直到队列为空
        int w;
        DeQueue(Q, e); // 出队一个顶点
        w = e.date;
        for (int i = 1; i <= G.vexnum; i++){ // 遍历所有顶点
            if (G.arcs[w][i] != MaxInt && !G.visited[i]){ // 如果顶点w与顶点i有边且顶点i未被访问过
                cout << G.vexs[i];   // 输出顶点i的数据元素
                G.visited[i] = true; // 标记顶点i为已访问
                e.date = i;
                EnQueue(Q, e); // 顶点i入队
            }
        }
    }
    DestroyQueue(Q); // 销毁队列Q
    return OK;
}

//=====主函数=========
int main()
{
    AMGraph amGraph; // 邻接矩阵
    cout << "定义: v1 = a ,v2 = b ,v3 = c ,v4 = d ,可达权值默认100" << endl;
    CreateUDN(amGraph);    // 调用邻接矩阵创建无向图函数
    InputAMGraph(amGraph); // 输出邻接矩阵无向图
    cout << "邻接矩阵深度优先遍历序列为:" << endl;
    ClearAMvisited(amGraph); // 清空邻接矩阵顶点访问标志
    DFS_AM(amGraph, 1);      // 调用邻接矩阵深度优先遍历函数
    cout << endl;
    cout << "邻接矩阵广度优先遍历序列为:" << endl;
    ClearAMvisited(amGraph); // 清空邻接矩阵顶点访问标志
    BFS_AM(amGraph, 1);      // 调用邻接矩阵广度优先遍历函数
    return 0;
}