typedef int VerTex;
using namespace std;
typedef int Status;
typedef struct
{
    VerTex date;
} QElemType;

typedef struct
{
    QElemType *base;
    int front;
    int rear;
} SqQueue;

Status InitQueue(SqQueue &Q)
{
    // 初始化队列
    Q.base = new QElemType[MAXSIZE];
    if (!Q.base)
        return ERROR;
    Q.front = 0;
    Q.rear = 0;
    return OK;
}

Status DestroyQueue(SqQueue &Q)
{
    // 销毁队列
    if (!Q.base)
        return ERROR;
    delete[] Q.base;
    Q.front = Q.rear = 0;
    return OK;
}

Status QueueEmpty(SqQueue Q)
{
    // 队列判空
    if (!Q.base)
        return ERROR;
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

Status EnQueue(SqQueue &Q, QElemType &e)
{
    // 入队
    if (!Q.base)
        return ERROR;
    Q.base[Q.rear % MAXSIZE] = e;
    Q.rear++;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
    // 出队
    if (!Q.base)
        return ERROR;
    e = Q.base[Q.front];
    Q.front++;
    return 0;
}