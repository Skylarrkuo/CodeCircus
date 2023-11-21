typedef char VertexType;
typedef int ArcTypr;
typedef int Status;
using namespace std;

//邻接表存储结构体
//边结点
typedef struct ArcNode {
    int adjvex;//该边指向顶点的位置
    struct ArcNode *nextarc;//指向下一条边
} ArcNode;
//表头结点，顶点信息
typedef struct VNode {
    VertexType data;//顶点数据元素
    ArcNode *firstarc;//指向下一个顶点
} VNode, AdjList[MVNum];
//邻接表主体
typedef struct {
    bool visited[MVNum];//顶点访问标志
    AdjList vertices;
    int vexnum, arcnum;//顶点数和边数
} ALGraph;

//邻接表的查找顶点位置
int ALLocateVex(ALGraph G, VertexType u) {
    int i;
    for (i = 0; i < G.vexnum; ++i)
        if (G.vertices[i].data == u)
            return i;
    return -1;
}
//邻接表创建无向图
Status CreateUDG(ALGraph &G) {
    int i, j, k;
    VertexType v1, v2;
    ArcNode *p1, *p2;
    cout << "请输入图的顶点数、边数（用空格隔开）：";
    cin >> G.vexnum >> G.arcnum;
    cout << "请输入" << G.vexnum << "个顶点的值：";
    cout<<endl;
    for (i = 0; i < G.vexnum; ++i) {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    cout << "请输入" ;
    cout << G.arcnum ;
    cout << "条边依附的两个端点(以空格作为间隔):" ;
    cout<<endl;
    for (k = 1; k <= G.arcnum; ++k) {
        cout << "请输入第" << k << "条边的信息：";
        cin >> v1 >> v2;
        i = ALLocateVex(G, v1);
        j = ALLocateVex(G, v2);
        p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
        p2 = new ArcNode;
        p2->adjvex = i;
        p1->nextarc = G.vertices[j].firstarc;
        G.vertices[j].firstarc = p2;
    }
    return OK;
}
//输出邻接表
void InputALGraph(ALGraph G) {
    int i;
    ArcNode *p;
    cout << G.vexnum << "个顶点:";
    for (i = 0; i < G.vexnum; ++i)
        cout << G.vertices[i].data << " ";
    cout << endl;
    cout << "邻接表为：" << endl;

    for (i = 0; i < G.vexnum; i++) {
        p = G.vertices[i].firstarc;
        cout << i << "|" << G.vertices[i].data;
        while (p) {
            cout << "|->" << p->adjvex;
            p = p->nextarc;

        }
        printf("|^\n");
    }
}
//清空邻接表顶点访问标志
Status ClearALvisited(ALGraph &G){
    for(int i=0;i<G.vexnum;i++){
        G.visited[i] = false;
    }
    return OK;
}

//邻接表深度优先遍历(递归)
Status DFS_AL(ALGraph G,int v){
    cout<<G.vertices[v].data;
    G.visited[v]=true;
    ArcNode *p=G.vertices[v].firstarc;
    while (p!=NULL){
        int w=p->adjvex;
        if(!G.visited[w]) DFS_AL(G,w);
        p=p->nextarc;
    }
}
//邻接表广度优先遍历(递归)