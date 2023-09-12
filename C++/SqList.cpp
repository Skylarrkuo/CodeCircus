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
{//����һ���յ�˳���L.
  L.elem=new ElemType[MAXSIZE];
  if(!L.elem)exit(OVERFLOW);
  L.length=0;
  return OK;
}

void SetList(SqList &L)
{ //Ϊ˳���L�ĸ�Ԫ�ظ�ֵ.
  int i, N;
  cout<<"������˳���ĳ���:";
  cin>>N;
  cout<<"�������������Ԫ��:";
  for(i=0;i<N;i++)
  {    cin>>L.elem[i];
       L.length++;
  }
 }

void ListTraverse(SqList L)
{//����˳���L.
  int i;
  cout<<"˳���Ϊ��" <<endl;
  for(i=0;i<=L.length-1;i++)
     cout<<L.elem[i]<<"  " ;
  cout<<endl;
  cout<<"��Ϊ��" <<L.length<<endl;
}

Status GetELem(SqList L, int i, ElemType &e)
{//ȡ˳���L�ĵ�i��Ԫ�ص�ֵ,��e����.
  e=L.elem[i-1];
  return OK;
}

int ListLength(SqList L)
{   
  return(L.length);
}

Status ListInsert (SqList &L,int i ,ElemType e)
{ //�����Ա�L�е�i������Ԫ��֮ǰ��������Ԫ��e 
   int j;
   if(i<1 || i>L.length+1) return ERROR;	      //iֵ���Ϸ�
   if(L.length==MAXSIZE) return ERROR; //�洢�ռ�����     
   for(j=L.length-1;j>=i-1;j--) 
       L.elem[j+1]=L.elem[j];    //����λ�ü�֮���Ԫ�غ���
   L.elem[i-1]=e;                     //����Ԫ��e�����i��λ��
    ++L.length;		     	//����1
   return OK;
}                                 

int LocateElem(SqList L, ElemType e)
{//��˳���L�в���ֵΪe������Ԫ�أ����������
    int i;
	for(i=0;i<L.length;i++)
	   if(L.elem[i]==e) return i+1;
	return 0;
}



int main()
{   SqList L;
    int i,j;
	ElemType e,f;
    if(InitList(L))	cout<<"��ʼ���ɹ�!"<<endl;
	SetList(L);
	ListTraverse(L);
	printf("��������ȡԪ�ص�λ��:");
	cin>>i;
	GetELem(L,i,e);
	cout<<"��ȡ�ĵ� "<<i<<" Ԫ��Ϊ:"<<e<<endl;
	cout<<"����������λ�ú�Ԫ��:";
	cin>>j>>f;
	ListInsert(L,j,f);
	ListTraverse(L);
	return 0;
}
