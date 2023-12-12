/*1．已知线性表 La 和 Lb 中的数据元素按值非递减有序排列，现要求将 La 和 Lb
归并为一个新的线性表 Lc，且 Lc 中的数据元素仍按值非递减有序排列。例如：
La=(1,2,3,4,5) Lb=(2, 4, 6, 8, 10)
合并之后：Lc=(1, 2, 2, 3, 4 ,4, 5,6,8, 10) */
#define MAXSIZE 100 // 线性表最大长度
#define OK 1
#define ERROR 0
#define OVERFLOW (-1)
#include <iostream>

using namespace std;

typedef int Status;
typedef struct ElemType
{ // 声明数据元素的结构体
    int data;
} ElemType;

typedef struct
{ // 声明线性表操作器
    ElemType *elem;
    int length;
} SqList;

// 12种操作
Status InitList(SqList *L)
{
    // 构建线性表
    L->elem = new ElemType[MAXSIZE];
    if (!L->elem)
        return ERROR;
    L->length = 0;
    return OK;
}
Status ListInsert(SqList &L, int i, ElemType e)
{
    // 在线性表L的i位置前插入元素e
    if (!L.elem && L.length == MAXSIZE) // 判断表是否存在以及是否有空间
        return ERROR;
    else
        for (int j = L.length - 1; j > i; j--)
            L.elem[j] = L.elem[j - 1];
    L.elem[i] = e;
    ++L.length;
    return OK;
}

int main()
{
    ElemType temp;
    ElemType a[5] = {1, 2, 3, 4, 5};
    ElemType b[5] = {2, 4, 6, 8, 10};
    SqList La, Lb, Lc;
    La.elem = a;
    La.length=5;
    Lb.elem = b;
    Lb.length=5;
    InitList(&Lc);

    //合并
    if(La.elem[0])
    for(int i=0,j=0;i<La.length+Lb.length;i++){
        if(La.elem[j].data<Lb.elem[j].data){
            Lc.elem[i]=La.elem[j];
            j++;
        }
    }
    return 0;
}