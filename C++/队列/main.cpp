#include <iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
using namespace std;

typedef int Status;

typedef struct {
    int date;
}QElemType;

typedef struct {
    QElemType *base;
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue &Q){
    //初始化队列
    Q.base=new QElemType[MAXSIZE];
    if(!Q.base) return ERROR;
    Q.front=0;
    Q.rear=0;
    return OK;
}

Status DestroyQueue(SqQueue &Q){
    //销毁队列
    if(!Q.base) return ERROR;
    delete[] Q.base;
    Q.front=Q.rear=0;
    return OK;
}

Status ClearQueue(SqQueue &Q){
    //清空队列
    if(!Q.base) return ERROR;
    Q.front=Q.rear=0;
}

Status QueueEmpty(SqQueue Q){
    //队列判空
    if(!Q.base) return ERROR;
    if(Q.front==Q.rear) return true;
    else return false;
}

Status QueueLength(SqQueue Q){
    if(!Q.base) return ERROR;
    return Q.rear-Q.front+1;
}

Status GetHead(SqQueue Q){
    //返回队头元素
    if(!Q.base) return ERROR;
    return Q.base[Q.front].date;
}

Status EnQueue(SqQueue &Q,QElemType &e){
    //入队
    if(!Q.base) return ERROR;
    Q.base[Q.rear%MAXSIZE+1]=e;
    Q.rear++;
    return OK;
}

Status DeQueue(SqQueue &Q,QElemType &e){
    //出队
    if(!Q.base) return ERROR;
    e=Q.base[Q.front];
    Q.front++;
    return 0;
}

Status QueueTraverse(SqQueue Q){
    //遍历队列
    if(!Q.base) return ERROR;
    for(int i=Q.front;i<=Q.rear;i++){
        cout<<Q.base[i%MAXSIZE].date<<endl;
    }
    return OK;
}


int main() {
    //调用队列的各种操作
int ZhuangTai= true;
    while (ZhuangTai){
        cout << "1.初始化"<<endl;
        cout << "2.先序存储二叉树"<<endl;
        cout << "3.先序遍历二叉树"<<endl;
        cout << "4.中序遍历二叉树"<<endl;
        cout << "5.后序遍历二叉树"<<endl;
        cout << "6.销毁二叉树"<<endl;
        cout << "7.清空二叉树"<<endl;
        cout << "0.退出"<<endl;

        cin>>ZhuangTai;
        switch (ZhuangTai) {
            case 1:
                BiTNode *T;
                system("pause");
                break;
            case 2:
                CreateBiTree_PreOrder(T);
                system("pause");
                break;
            case 3:
                if(T->Date){
                    PreOrderTraverse(T);
                }
                system("pause");
                break;
            case 4:
                if(T->Date){
                    PreOrderTraverse(T);
                }
                system("pause");
                break;
            case 5:
                if(T->Date){
                    InOrderTraverse(T);
                }
                system("pause");
                break;
            case 6:
                if(T->Date){
                    DestroyBiTree(T);
                }else{
                    cout<<"二叉树已经不存在"<<endl;
                }
                system("pause");
                break;
            case 7:
                break;
        }
        system("cls");
    }
    
    return 0;
}
