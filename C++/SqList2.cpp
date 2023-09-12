#define MAXSIZE 100 // 线性表最大长度
#define OK 1
#define ERROR 0
#define OVERFLOW -1

#include <iostream>
using namespace std;

typedef int Status;

typedef struct
{ // 声明图书数据元素的结构体
    char no[20];
    char name[50];
    double price;
} Book;

typedef struct
{ // 声明线性表操作器
    Book *elem;
    int length;
} SqList;

// 12种操作//

Status InitList(SqList &L)
{
    // 构建线性表
    L.elem = new Book[MAXSIZE];
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    return OK;
}

Status DestroyList(SqList &L)
{
    // 销毁线性表L
    if (!L.elem)
        exit(OVERFLOW);
    else
        delete[] L.elem;
    L.length = 0;
    return OK;
}

Status ClearList(SqList &L)
{
    // 重置线性表L
    if (!L.elem)
        exit(OVERFLOW);
    else
        L.length = 0;
    return OK;
}

Status ListEmpty(SqList L)
{
    // 判空线性表L
    if (L.length == 0)
        return true;
    else
        return false;
}

Status DestroyList(SqList L)
{
    // 返回线性表L元素个数
    if (!L.elem)
        exit(OVERFLOW);
    else
        return L.length;
}

Status GetElem(SqList L, int i, Book &e)
{
    // 用e返回L中第i个数据元素的值
    if (!L.elem)
        exit(OVERFLOW);
    else if (i >= 1 && i <= L.length)
        e = L.elem[i + 1];
    return e;
}

Status LocateElem(SqList L, Book e)
{
    // 查找线性表L中元素并返回位置
    if (!L.elem)
        exit(OVERFLOW);
    else
        for (int i = 0; i < L.length; i++)
        {
            if (L.elem[i] == e)
                return i + 1;
        }
    return 0;
}

Status PriorElem(SqList L, Book cur_e, Book &Pre_e)
{
    // 取cur_e在线性表L中前驱
    if (!L.elem)
        exit(OVERFLOW);
    else if (LocateElem(L, cur_e) != 0 && LocateElem(L, cur_e) != 1)
        Pre_e = L.elem[LocateElem(L, cur_e) - 1];
    else
        return Pre_e;
    return Pre_e;
}

Status NextElem(SqList L, Book cur_e, Book &Next_e)
{
    // 取cur_e在线性表L中后继
    if (!L.elem)
        exit(OVERFLOW);
    else if (LocateElem(L, cur_e) != 0 && LocateElem(L, cur_e) != L.length)
        Pre_e = L.elem[LocateElem(L, cur_e) + 1];
    else
        return Next_e;
    return Next_e;
}

Status ListInsert(SqList &L, int i, Book e)
{
    // 在线性表L的i位置前插入元素e
}

Status ListDelete(SqList &L, int i)
{
    // 删除线性表L中第i个元素
}

Status TraverseList(SqList L)
{
    // 对线性表L的每个节点进行遍历
}
