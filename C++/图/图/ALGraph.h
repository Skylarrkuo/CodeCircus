

typedef char VertexType;
typedef int ArcTypr;
typedef int Status;
using namespace std;

typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode {
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MVNum];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;

} ALGraph;

/****************************************************************ͼ���ڽӱ��ʾ��ز���**********************/

int LocateVex(ALGraph G, VertexType u) {
    int i;
    for (i = 0; i < G.vexnum; ++i)
        if (G.vertices[i].data == u)
            return i;
    return -1;
}
Status CreateUDG(ALGraph &G) {
    int i, j, k;
    VertexType v1, v2;
    ArcNode *p1, *p2;
    cout << "������ͼ�Ķ��������������ÿո��������";
    cin >> G.vexnum >> G.arcnum;
    cout << "������" << G.vexnum << "�������ֵ��";
    cout<<endl;
    for (i = 0; i < G.vexnum; ++i) {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    cout << "������" ;
    cout << G.arcnum ;
    cout << "���������������˵�(�Կո���Ϊ���):" ;
    cout<<endl;
    for (k = 1; k <= G.arcnum; ++k) {
        cout << "�������" << k << "���ߵ���Ϣ��";
        cin >> v1 >> v2;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
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
void Display(ALGraph G) {
    int i;
    ArcNode *p;
    cout << G.vexnum << "������:";
    for (i = 0; i < G.vexnum; ++i)
        cout << G.vertices[i].data << " ";
    cout << endl;
    cout << "�ڽӱ�Ϊ��" << endl;

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