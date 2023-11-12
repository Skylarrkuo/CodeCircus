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

