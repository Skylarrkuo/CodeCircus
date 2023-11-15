#include<iostream>
using namespace std;
#define	OK	1
#define	ERROR	0
#define MVNum	100	//最大定点数
#define VertexType  char 
#define OK 1
typedef int Status;

typedef	struct ArcNode {
	int				adjvex;		//该弧所指向的顶点的位置
	struct ArcNode	*nextarc;	//指向下一条弧的指针
}ArcNode;

typedef struct VNode {
	VertexType	data;		//顶点信息
	ArcNode		*firstarc;	//指向第一条依附该顶点的弧的指针
}VNode,	AdjList[MVNum];	//一维数组，用来分布不同顶点

typedef struct {
	AdjList		vertices;
	int			vexnum, arcnum;	//弧的当前顶点数和弧数

}ALGraph;

/***********************************************************图的邻接表表示的相关操作***************************************************************************************************/

int LocateVex(ALGraph G,VertexType u)
 { /* 初始条件: 图G存在,u和G中顶点有相同特征 */
   /* 操作结果: 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
   int i;
   for(i=0;i<G.vexnum;++i)
     if(G.vertices[i].data==u)
       return i;
   return -1;
 }


Status CreateUDG(ALGraph &G)
 { //采用邻接表存储结构,构造无向图G
   int i,j,k;
   VertexType v1,v2;
   ArcNode *p1,*p2;
   cout<<"请输入图的顶点数、边数（用空格隔开）: ";
   cin>>G.vexnum>>G.arcnum;
   cout<<"请输入"<<G.vexnum<<"个顶点的值:";
   for(i=0;i<G.vexnum;++i) /* 构造顶点向量 */
   {
     cin>>G.vertices[i].data;
     G.vertices[i].firstarc=NULL;
   }
  
   cout<<"请输入"<<G.arcnum<<"条边依附的两个端点(以空格作为间隔): "<<endl;
   for(k=1;k<=G.arcnum;++k) /* 构造表结点链表 */
   { cout<<"请输入第"<<k<<"条边的信息:";
     cin>>v1>>v2;
     i=LocateVex(G,v1); /* 弧尾 */
     j=LocateVex(G,v2); /* 弧头 */
     p1=new ArcNode;
     p1->adjvex=j;
     p1->nextarc=G.vertices[i].firstarc; /* 插在第i表表头 */
     G.vertices[i].firstarc=p1;
     p2=new ArcNode;
     p2->adjvex=i;
     p2->nextarc=G.vertices[j].firstarc; /* 插在第j表表头 */
     G.vertices[j].firstarc=p2;
     }
   return OK;
 }


void Display(ALGraph G)
 { /* 输出图的邻接表G */
   int i;
   ArcNode *p;
   cout<<G.vexnum<<"个顶点:";
   for(i=0;i<G.vexnum;++i)
     cout<<G.vertices[i].data<<"  ";
   cout<<endl;
   cout<<"邻接表为:"<<endl;
   for(i=0;i<G.vexnum;i++)
   {
     p=G.vertices[i].firstarc;
	 cout<<i<<"|"<<G.vertices[i].data;
     while(p)
     {
        cout<<"|->"<<p->adjvex;
		p=p->nextarc;
        
       }
       
     printf("|^\n");
   }
 }

int main(){
	ALGraph G;
	CreateUDG(G);
	cout<<endl;
	Display(G);
    return 0;
}
