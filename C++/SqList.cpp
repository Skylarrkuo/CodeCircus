#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100
using namespace std;

typedef int Status;
typedef int ElemType;
typedef struct {
	ElemType *elem;
	int length;
}SqList;


Status InitList(SqList &L)
{//构造一个空的顺序表L.
  L.elem=new ElemType[MAXSIZE];
  if(!L.elem)exit(OVERFLOW);
  L.length=0;
  return OK;
}

void SetList(SqList &L)
{ //为顺序表L的各元素赋值.
  int i, N;
  cout<<"请输入顺序表的长度:";
  cin>>N;
  cout<<"请输入各个数据元素:";
  for(i=0;i<N;i++)
  {    cin>>L.elem[i];
       L.length++;
  }
 }

void ListTraverse(SqList L)
{//遍历顺序表L.
  int i;
  cout<<"顺序表为：" <<endl;
  for(i=0;i<=L.length-1;i++)
     cout<<L.elem[i]<<"  " ;
  cout<<endl;
  cout<<"表长为：" <<L.length<<endl;
}

Status GetELem(SqList L, int i, ElemType &e)
{//取顺序表L的第i个元素的值,用e返回.
  e=L.elem[i-1];
  return OK;
}

int ListLength(SqList L)
{   
  return(L.length);
}

Status ListInsert (SqList &L,int i ,ElemType e)
{ //在线性表L中第i个数据元素之前插入数据元素e 
   int j;
   if(i<1 || i>L.length+1) return ERROR;	      //i值不合法
   if(L.length==MAXSIZE) return ERROR; //存储空间已满     
   for(j=L.length-1;j>=i-1;j--) 
       L.elem[j+1]=L.elem[j];    //插入位置及之后的元素后移
   L.elem[i-1]=e;                     //将新元素e放入第i个位置
    ++L.length;		     	//表长增1
   return OK;
}                                 

int LocateElem(SqList L, ElemType e)
{//在顺序表L中查找值为e的数据元素，返回其序号
    int i;
	for(i=0;i<L.length;i++)
	   if(L.elem[i]==e) return i+1;
	return 0;
}



int main()
{   SqList L;
    int i,j;
	ElemType e,f;
    if(InitList(L))	cout<<"初始化成功!"<<endl;
	SetList(L);
	ListTraverse(L);
	printf("请输入所取元素的位序:");
	cin>>i;
	GetELem(L,i,e);
	cout<<"所取的第 "<<i<<" 元素为:"<<e<<endl;
	cout<<"请输入插入的位置和元素:";
	cin>>j>>f;
	ListInsert(L,j,f);
	ListTraverse(L);
	return 0;
}
