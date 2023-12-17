#include <iostream>
using namespace std;
#define MaxInt 32767 // 最大值
#define MVNum 100	 // 最大顶点数
#define ERROR 0
#define OK 1

// typedef enum {DG,DN,UDG,UDN} GraphKind;	//{有向图，有向网，无向图，无向网}标志位
typedef int ArcType;
typedef char VertexType;
typedef int Status;

typedef struct
{
	VertexType vexs[MVNum];		// 顶点向量
	ArcType arcs[MVNum][MVNum]; // 邻接矩阵
	int vexnum, arcnum;			// 图的当前顶点数和弧数
} AMGraph;

//**********************************************************图的邻接矩阵表示的相关操作***************************************************************************************************/

/*图的构建*/
int LocateVex(AMGraph G, VertexType u)
{ /* 初始条件: 图G存在,u和G中顶点有相同特征 */
	/* 操作结果: 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (u == G.vexs[i])
			return i;
	return -1;
}

Status CreateUDN(AMGraph &G)
{
	// 采用邻接矩阵表示法，创建无向网G
	int i, j, k, w;
	VertexType v1, v2;
	cout << "请输入无向图G的顶点数(不超过100个)、边数，以空格隔开: ";
	cin >> G.vexnum >> G.arcnum;
	cout << "请输入" << G.vexnum << "个顶点的值:" << endl;
	for (i = 0; i < G.vexnum; ++i) // 构造顶点向量
		cin >> G.vexs[i];
	for (i = 0; i < G.vexnum; ++i) // 初始化邻接矩阵
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j] = MaxInt; // 所有关系初始为MaxInt
		}
	cout << "请输入" << G.arcnum << "条边依附的顶点和权值(以空格作为间隔): " << endl;
	for (k = 1; k <= G.arcnum; ++k)
	{
		cout << "第" << k << "条：";
		cin >> v1 >> v2 >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		if (i == -1 || j == -1)
			return 0;
		G.arcs[i][j] = w;
		G.arcs[j][i] = w; // 无向
	}
	return OK;
}

Status PrintMGraph(AMGraph G)
{
	// 输出邻接矩阵
	int i, j;
	cout << "构造的邻接矩阵为：" << endl;
	for (i = 0; i < G.vexnum; ++i)
	{
		for (j = 0; j < G.vexnum; ++j)
			cout << G.arcs[i][j] << "       ";
		cout << endl;
	} // 输出构造的矩阵
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
