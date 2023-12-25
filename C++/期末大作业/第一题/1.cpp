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

Status InitList(SqList *L)
{
    // 构建线性表
    L->elem = new ElemType[MAXSIZE];
    if (!L->elem)
        return ERROR;
    L->length = 0;
    return OK;
}

Status MegerList(SqList &La, SqList &Lb, SqList &Lc)
{
    // 归并线性表
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < La.length || j < Lb.length; k++, Lc.length++)
    {
        if (i >= La.length){
            Lc.elem[k] = Lb.elem[j];
            j++;
        }
        else if (j >= Lb.length){
            Lc.elem[k] = La.elem[i];
            i++;
        }
        else if (La.elem[i].data < Lb.elem[j].data){
            Lc.elem[k] = La.elem[i];
            i++;
        }
        else{
            Lc.elem[k] = Lb.elem[j];
            j++;
        }
    }
    return OK;
}

int main()
{
    int i, j, k;
    // 自定义数据
    ElemType a[5] = {1, 2, 3, 4, 5};
    ElemType b[5] = {2, 4, 6, 8, 10};

    // 初始化三个线性表
    SqList La, Lb, Lc;
    La.elem = a;
    La.length = 5;
    Lb.elem = b;
    Lb.length = 5;
    InitList(&Lc);

    // 输出La和Lb
    cout << "La= ";
    for (i = 0; i < La.length; i++){
        printf("%d ", La.elem[i].data);
    }
    cout << "\nLb= ";
    for (i = 0; i < Lb.length; i++){
        printf("%d ", Lb.elem[i].data);
    }
    // 归并
    MegerList(La, Lb, Lc);

    // 输出归并后的Lc
    cout << "\nLc= ";
    for (i = 0; i < Lc.length; i++){
        printf("%d ", Lc.elem[i].data);
    }

    return 0;
}