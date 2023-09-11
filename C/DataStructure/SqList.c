#define MAXSIZE 100 //线性表最大长度
#include <stdio.h>

//声明图书的结构体
typedef struct
{
    char no[20];
    char name[50];
    float price;
}Book;

//声明线性表操作器
typedef struct
{
    Book *elme;
    int length;
}SqList;

//12种操作

Status InitList(SqList &L){
    //构建线性表

}

Status DestroyList(SqList &L){
    //销毁线性表L

}

Status ClearList(SqList &L){
    //重置线性表L

}

Status ListEmpty(SqList L){
    //判空线性表L

}

Status DestroyList(SqList L){
    //返回线性表L元素个数

}

Status GetElem(SqList L,int i,ElemType &e){
    //用e返回L中第i个数据元素的值

}

Status LocateElem(SqList L,int e){
    //查找线性表L中元素并返回位置

}

Status PriorElem(SqList L,ElemType cur_e,ElemType &Pre_e){
    //取cur_e在线性表L中前驱
}

Status NextElem(SqList L,ElemType cur_e,ElemType &Next_e){
    //取cur_e在线性表L中后继

}

Status ListInsert(SqList &L,int i,ElemType e){
    //在线性表L的i位置前插入元素e

}

Status ListDelete(SqList &L,int i){
    //删除线性表L中第i个元素

}

Status TraverseList(SqList L){
    //对线性表L的每个节点进行遍历

}