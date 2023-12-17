#include <iostream>
using namespace std;
#define MaxInt 32767 // ���ֵ
#define MVNum 100	 // ��󶥵���
#define ERROR 0
#define OK 1

// typedef enum {DG,DN,UDG,UDN} GraphKind;	//{����ͼ��������������ͼ��������}��־λ
typedef int ArcType;
typedef char VertexType;
typedef int Status;

typedef struct
{
	VertexType vexs[MVNum];		// ��������
	ArcType arcs[MVNum][MVNum]; // �ڽӾ���
	int vexnum, arcnum;			// ͼ�ĵ�ǰ�������ͻ���
} AMGraph;

//**********************************************************ͼ���ڽӾ����ʾ����ز���***************************************************************************************************/

/*ͼ�Ĺ���*/
int LocateVex(AMGraph G, VertexType u)
{ /* ��ʼ����: ͼG����,u��G�ж�������ͬ���� */
	/* �������: ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1 */
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (u == G.vexs[i])
			return i;
	return -1;
}

Status CreateUDN(AMGraph &G)
{
	// �����ڽӾ����ʾ��������������G
	int i, j, k, w;
	VertexType v1, v2;
	cout << "����������ͼG�Ķ�����(������100��)���������Կո����: ";
	cin >> G.vexnum >> G.arcnum;
	cout << "������" << G.vexnum << "�������ֵ:" << endl;
	for (i = 0; i < G.vexnum; ++i) // ���춥������
		cin >> G.vexs[i];
	for (i = 0; i < G.vexnum; ++i) // ��ʼ���ڽӾ���
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j] = MaxInt; // ���й�ϵ��ʼΪMaxInt
		}
	cout << "������" << G.arcnum << "���������Ķ����Ȩֵ(�Կո���Ϊ���): " << endl;
	for (k = 1; k <= G.arcnum; ++k)
	{
		cout << "��" << k << "����";
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		if (i == -1 || j == -1)
			return 0;
		G.arcs[i][j] = w;
		G.arcs[j][i] = w; // ����
	}
	return OK;
}

Status PrintMGraph(AMGraph G)
{
	// ����ڽӾ���
	int i, j;
	cout << "������ڽӾ���Ϊ��" << endl;
	for (i = 0; i < G.vexnum; ++i)
	{
		for (j = 0; j < G.vexnum; ++j)
			cout << G.arcs[i][j] << "       ";
		cout << endl;
	} // �������ľ���
	return OK;
}

int main()
{
	AMGraph G;
	CreateUDN(G);
	cout << endl;
	PrintMGraph(G);
	return 0;
}
