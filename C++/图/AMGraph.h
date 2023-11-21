#define MVNum 100
#define MaxInt 32767
typedef char VerTexType;
typedef int ArcTypr;
typedef int Status;
using namespace std;
#include"SQueue.h"
// �ڽӾ�������ͼ�洢�ṹ
typedef struct
{
    bool visited[MVNum];
    VerTexType vexs[MVNum];
    ArcTypr arcs[MVNum][MVNum];
    int vexnum = 0, arcnum = 0;
} AMGraph;

// �ڽӾ���Ĳ��Ҷ���λ��
Status LocateVex(AMGraph G, VerTexType v)
{
    int k;
    for (k = 1; k <= G.vexnum; k++)
    {
        if (G.vexs[k] == v) break;
    }
    if (k > G.vexnum)
        return -1;
    return k;
}

// �����ڽӾ�������ͼ
Status CreateUDN(AMGraph &G)
{
    char v1, v2;
    int i, j, k, w;
    cout << "��������ͼ�Ķ����������ͱ������ÿո����(<100)��" << endl;
    cin >> G.vexnum >> G.arcnum;
    for (k = 1; k <= G.arcnum; k++)
    {
        cout << "�����" << k << "������:";
        cin >> G.vexs[k];
    }
    // �����ڽӾ���
    for (i = 1; i <= G.vexnum; i++)
    {
        for (j = 1; j <= G.vexnum; j++)
        {
            G.arcs[i][j] = MaxInt;
        }
    }

    for (k = 1; k <= G.arcnum; k++)
    {
        cout << "�����" << k << "���������ĵĶ��㼰Ȩֵ:";
        cin >> v1 >> v2 >> w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = w;
    }
    return OK;
}

// ����ڽӾ�������ͼ
Status InputAMGraph(AMGraph G)
{
    int i, j, k;
    cout << "�ڽӾ�������ͼ�Ķ����У�" << endl;
    for (k = 1; k <= G.vexnum; k++)
    {
        printf("%c ", G.vexs[k]);
    }
    cout << endl;
    cout << "�ڽӾ���λ��" << endl;
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
//����ڽӱ�����ʱ�־
Status ClearAMvisited(AMGraph &G){
    for(int i=0;i<G.vexnum;i++){
        G.visited[i] = false;
    }
    return OK;
}
//�ڽӾ���������ȱ���(�ݹ�)
Status DFS_AM(AMGraph G,int v){
    //GΪ�ڽӾ��󣬴ӵ�v����������������������
    cout<<G.vexs[v];
    G.visited[v]=true;
    for(int w=0;w<G.vexnum;w++) {
        if ((G.arcs[v][w] != MaxInt) && (!G.visited[w])) DFS_AM(G, w);
    }
}
//�ڽӾ��������ȱ���(�ݹ�)
Status BFS_AM(AMGraph G,int v){
    VerTexType u, w;
    SqQueue Q; // ��������
    cout << G.vexs[v];
    G.visited[v] = true;
    InitQueue(Q);
    EnQueue(Q, G.vexs[v]);
    while(!QueueEmpty(Q)){
        DeQueue(Q, u);
        for(w=FirstAdjVex(G.u)){
            
        }
    }
}