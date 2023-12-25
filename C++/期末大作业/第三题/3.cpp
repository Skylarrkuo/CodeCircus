/*1��ʹ���ڽӾ�������ڽӱ���һ��������ʾ������ͼ,�����������������
�͹���������� 2 �ֱ����㷨��ͼ���б���.*/
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

//=====����===========
typedef struct{
    VerTex date;
} QElemType;

typedef struct{
    QElemType *base;
    int front;
    int rear;
} SqQueue;

Status InitQueue(SqQueue &Q){
    // ��ʼ������
    Q.base = new QElemType[MAXSIZE];
    if (!Q.base)
        return ERROR;
    Q.front = 0;
    Q.rear = 0;
    return OK;
}

Status DestroyQueue(SqQueue &Q){
    // ���ٶ���
    if (!Q.base)
        return ERROR;
    delete[] Q.base;
    Q.front = Q.rear = 0;
    return OK;
}

Status QueueEmpty(SqQueue Q){
    // �����п�
    if (!Q.base)
        return ERROR;
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

Status EnQueue(SqQueue &Q, QElemType &e){
    // ���
    if (!Q.base)
        return ERROR;
    Q.base[Q.rear % MAXSIZE] = e;
    Q.rear++;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e){
    // ����
    if (!Q.base)
        return ERROR;
    e = Q.base[Q.front];
    Q.front++;
    return 0;
}

//===�ڽӾ���=================================
// �ڽӾ�������ͼ�洢�ṹ
typedef struct{
    bool visited[MVNum];
    VerTexType vexs[MVNum];
    ArcTypr arcs[MVNum][MVNum];
    int vexnum = 0, arcnum = 0;
} AMGraph;

// �ڽӾ���Ĳ��Ҷ���λ��
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

// �����ڽӾ�������ͼ
Status CreateUDN(AMGraph &G){
    char v1, v2;
    int i, j, k, w;
    cout << "��������ͼ�Ķ����������ͱ���,�ÿո����:";
    cin >> G.vexnum >> G.arcnum;
    cout << "����" << G.vexnum << "������:";
    for (k = 1; k <= G.arcnum; k++){
        cin >> G.vexs[k];
    }
    // �����ڽӾ���
    for (i = 1; i <= G.vexnum; i++){
        for (j = 1; j <= G.vexnum; j++){
            G.arcs[i][j] = MaxInt;
        }
    }

    for (k = 1; k <= G.arcnum; k++){
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
Status InputAMGraph(AMGraph G){
    int i, j, k;
    cout << "�ڽӾ�������ͼ�Ķ�����:" << endl;
    for (k = 1; k <= G.vexnum; k++){
        printf("%c ", G.vexs[k]);
    }
    cout << endl;
    cout << "�ڽӾ���λ:" << endl;
    for (i = 1; i <= G.vexnum; i++){
        printf("|");
        for (j = 1; j <= G.vexnum; j++){
            printf("%d\t", G.arcs[i][j]);
        }
        printf("|\n");
    }
    return OK;
}
// ����ڽӱ�����ʱ�־
Status ClearAMvisited(AMGraph &G){
    for (int i = 0; i <= G.vexnum; i++){
        G.visited[i] = false;
    }
    return OK;
}
// �ڽӾ���������ȱ���(�ݹ�)
Status DFS_AM(AMGraph &G, int v){
    // GΪ�ڽӾ���,�ӵ�v����������������������
    cout << G.vexs[v];
    G.visited[v] = true;
    for (int w = 0; w <= G.vexnum; w++){
        if ((G.arcs[v][w] != MaxInt) && (!G.visited[w]))
            DFS_AM(G, w);
    }
    return OK;
}

// �ڽӾ��������ȱ���
Status BFS_AM(AMGraph G, int v){
    SqQueue Q;           // ����һ������Q
    InitQueue(Q);        // ��ʼ������Q
    cout << G.vexs[v];   // �����ʼ���������Ԫ��
    G.visited[v] = true; // �����ʼ����Ϊ�ѷ���
    QElemType e;
    e.date = v;
    EnQueue(Q, e);         // ��ʼ�������
    while (!QueueEmpty(Q)){ // ѭ��ֱ������Ϊ��
        int w;
        DeQueue(Q, e); // ����һ������
        w = e.date;
        for (int i = 1; i <= G.vexnum; i++){ // �������ж���
            if (G.arcs[w][i] != MaxInt && !G.visited[i]){ // �������w�붥��i�б��Ҷ���iδ�����ʹ�
                cout << G.vexs[i];   // �������i������Ԫ��
                G.visited[i] = true; // ��Ƕ���iΪ�ѷ���
                e.date = i;
                EnQueue(Q, e); // ����i���
            }
        }
    }
    DestroyQueue(Q); // ���ٶ���Q
    return OK;
}

//=====������=========
int main()
{
    AMGraph amGraph; // �ڽӾ���
    cout << "����: v1 = a ,v2 = b ,v3 = c ,v4 = d ,�ɴ�ȨֵĬ��100" << endl;
    CreateUDN(amGraph);    // �����ڽӾ��󴴽�����ͼ����
    InputAMGraph(amGraph); // ����ڽӾ�������ͼ
    cout << "�ڽӾ���������ȱ�������Ϊ:" << endl;
    ClearAMvisited(amGraph); // ����ڽӾ��󶥵���ʱ�־
    DFS_AM(amGraph, 1);      // �����ڽӾ���������ȱ�������
    cout << endl;
    cout << "�ڽӾ��������ȱ�������Ϊ:" << endl;
    ClearAMvisited(amGraph); // ����ڽӾ��󶥵���ʱ�־
    BFS_AM(amGraph, 1);      // �����ڽӾ��������ȱ�������
    return 0;
}