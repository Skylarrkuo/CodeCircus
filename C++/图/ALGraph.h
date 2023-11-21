typedef char VertexType;
typedef int ArcTypr;
typedef int Status;
using namespace std;

//�ڽӱ�洢�ṹ��
//�߽��
typedef struct ArcNode {
    int adjvex;//�ñ�ָ�򶥵��λ��
    struct ArcNode *nextarc;//ָ����һ����
} ArcNode;
//��ͷ��㣬������Ϣ
typedef struct VNode {
    VertexType data;//��������Ԫ��
    ArcNode *firstarc;//ָ����һ������
} VNode, AdjList[MVNum];
//�ڽӱ�����
typedef struct {
    bool visited[MVNum];//������ʱ�־
    AdjList vertices;
    int vexnum, arcnum;//�������ͱ���
} ALGraph;

//�ڽӱ�Ĳ��Ҷ���λ��
int ALLocateVex(ALGraph G, VertexType u) {
    int i;
    for (i = 0; i < G.vexnum; ++i)
        if (G.vertices[i].data == u)
            return i;
    return -1;
}
//�ڽӱ�������ͼ
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
//����ڽӱ�
void InputALGraph(ALGraph G) {
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
//����ڽӱ�����ʱ�־
Status ClearALvisited(ALGraph &G){
    for(int i=0;i<G.vexnum;i++){
        G.visited[i] = false;
    }
    return OK;
}

//�ڽӱ�������ȱ���(�ݹ�)
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
//�ڽӱ������ȱ���(�ݹ�)