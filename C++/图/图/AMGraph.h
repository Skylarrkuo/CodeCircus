#define MVNum 100
#define MaxInt 32767
typedef char VerTexType;
typedef int ArcTypr;
typedef int Status;
using namespace std;

// 邻接矩阵无向图存储结构
typedef struct
{
    VerTexType vexs[MVNum];
    ArcTypr arcs[MVNum][MVNum];
    int vexnum = 0, arcnum = 0;
} AMGraph;

// 查找定点是否存在并返回位置
Status LocateVex(AMGraph G, VerTexType v)
{
    int k;
    for (k = 1; k <= G.vexnum; k++)
    {
        if (G.vexs[k] == v)
        {
            break;
        }
    }
    if (k > G.vexnum)
        return -1;
    return k;
}

// 构造邻接矩阵无向图
Status CreateUDN(AMGraph &G)
{
    char v1, v2;
    int i, j, k, w;
    cout << "输入无向图的定点数个数和边数，用空格隔开(<100)：" << endl;
    cin >> G.vexnum >> G.arcnum;
    for (k = 1; k <= G.arcnum; k++)
    {
        cout << "输入第" << k << "个节点:";
        cin >> G.vexs[k];
    }
    // 构造邻接矩阵
    for (i = 1; i <= G.vexnum; i++)
    {
        for (j = 1; j <= G.vexnum; j++)
        {
            G.arcs[i][j] = MaxInt;
        }
    }

    for (k = 1; k <= G.arcnum; k++)
    {
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
Status InputAMGraph(AMGraph G)
{
    int i, j, k;
    cout << "邻接矩阵无向图的定点有：" << endl;
    for (k = 1; k <= G.vexnum; k++)
    {
        printf("%c ", G.vexs[k]);
    }
    cout << endl;
    cout << "邻接矩阵位：" << endl;
    for (i = 1; i <= G.vexnum; i++)
    {
        printf("|");
        for (j = 1; j <= G.vexnum; j++)
        {
            printf("%d\t", G.arcs[i][j]);
        }
        printf("|\n");
    }
}
