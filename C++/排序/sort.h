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

//=============排序算法================
void InsertSort(SqList &L)
{
    // 对顺序表L做直接插入排序
}
void BubbleSort(SqList &L)
{
    // 对顺序表L做冒泡排序
}
void BInsertSort(SqList &L)
{
    // 对顺序表L进行这般插入排序
}
void ShellInsert(SqList &L){
    //对顺序表L进行一趟希尔增量排序

}

void Shell