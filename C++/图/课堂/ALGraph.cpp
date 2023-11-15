#include<iostream>
using namespace std;
#define	OK	1
#define	ERROR	0
#define MVNum	100	//��󶨵���
#define VertexType  char 
#define OK 1
typedef int Status;

typedef	struct ArcNode {
	int				adjvex;		//�û���ָ��Ķ����λ��
	struct ArcNode	*nextarc;	//ָ����һ������ָ��
}ArcNode;

typedef struct VNode {
	VertexType	data;		//������Ϣ
	ArcNode		*firstarc;	//ָ���һ�������ö���Ļ���ָ��
}VNode,	AdjList[MVNum];	//һά���飬�����ֲ���ͬ����

typedef struct {
	AdjList		vertices;
	int			vexnum, arcnum;	//���ĵ�ǰ�������ͻ���

}ALGraph;

/***********************************************************ͼ���ڽӱ��ʾ����ز���***************************************************************************************************/

int LocateVex(ALGraph G,VertexType u)
 { /* ��ʼ����: ͼG����,u��G�ж�������ͬ���� */
   /* �������: ��G�д��ڶ���u,�򷵻ظö�����ͼ��λ��;���򷵻�-1 */
   int i;
   for(i=0;i<G.vexnum;++i)
     if(G.vertices[i].data==u)
       return i;
   return -1;
 }


Status CreateUDG(ALGraph &G)
 { //�����ڽӱ�洢�ṹ,��������ͼG
   int i,j,k;
   VertexType v1,v2;
   ArcNode *p1,*p2;
   cout<<"������ͼ�Ķ��������������ÿո������: ";
   cin>>G.vexnum>>G.arcnum;
   cout<<"������"<<G.vexnum<<"�������ֵ:";
   for(i=0;i<G.vexnum;++i) /* ���춥������ */
   {
     cin>>G.vertices[i].data;
     G.vertices[i].firstarc=NULL;
   }
  
   cout<<"������"<<G.arcnum<<"���������������˵�(�Կո���Ϊ���): "<<endl;
   for(k=1;k<=G.arcnum;++k) /* ����������� */
   { cout<<"�������"<<k<<"���ߵ���Ϣ:";
     cin>>v1>>v2;
     i=LocateVex(G,v1); /* ��β */
     j=LocateVex(G,v2); /* ��ͷ */
     p1=new ArcNode;
     p1->adjvex=j;
     p1->nextarc=G.vertices[i].firstarc; /* ���ڵ�i���ͷ */
     G.vertices[i].firstarc=p1;
     p2=new ArcNode;
     p2->adjvex=i;
     p2->nextarc=G.vertices[j].firstarc; /* ���ڵ�j���ͷ */
     G.vertices[j].firstarc=p2;
     }
   return OK;
 }


void Display(ALGraph G)
 { /* ���ͼ���ڽӱ�G */
   int i;
   ArcNode *p;
   cout<<G.vexnum<<"������:";
   for(i=0;i<G.vexnum;++i)
     cout<<G.vertices[i].data<<"  ";
   cout<<endl;
   cout<<"�ڽӱ�Ϊ:"<<endl;
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
