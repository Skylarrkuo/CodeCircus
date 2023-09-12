#define MAXSIZE 100 // 线性表最大长度
#define OK 1
#define ERROR 0
#define OVERFLOW (-1)
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <fstream>

using namespace std;

typedef int Status;
typedef struct
{ // 声明图书数据元素的结构体
    string id;
    string name;
    double price;
} Book;

typedef struct
{ // 声明线性表操作器
    Book *elem;
    int length;
} SqList;

//
int main(){
    ifstream Read;
    ofstream Write;
    int s=1;
    while (s!=0){
        system("cls");
        cout << "===========欢迎使用图书管理系统============="<<endl;
        cout << "\t1.建立图书表\t7.清空图书表"<<endl;
        cout << "\t2.输入数据项\t8.取数据项前驱"<<endl;
        cout << "\t3.表中取值项\t9.取数据项后继"<<endl;
        cout << "\t4.查找数据项\t10.数据项个数"<<endl;
        cout << "\t5.插入数据项\t11.退出系统"<<endl;
        cout << "\t6.删除数据项\t"<<endl;
        cout << "==========输入对应数字进行操作==========\n>>:";
        cin>>s;
        system("cls");
        switch(s)
        {
            case 1 :
                infile.open("Book.txt");

                break;
            case 2 :
                break;
            case 3 :
                break;
            case 4 :
                break;
            case 5 :
                break;
            case 6 :
                break;
            case 7 :
                break;
            case 8 :
                break;
            case 9 :
                break;
            case 10 :
                break;
            case 11 :
                break;
            case 12 :
                break;
            default :
                cout << "\n无效的输入！！" << endl;
                sleep(3);
        }

    }
    return 0;
}
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
    return OK;
}

Status LocateElem(SqList L, Book &e)
{
    // 查找线性表L中元素并返回位置
    if (!L.elem)
        exit(OVERFLOW);
    else
        for (int i = 0; i < L.length; i++)
        {
            if (memcmp(&L.elem[i], &e, sizeof(Book))) return i + 1;
        }
}

Status PriorElem(SqList L, Book cur_e, Book &Pre_e)
{
    // 取cur_e在线性表L中前驱
    if (!L.elem)
        exit(OVERFLOW);
    else if (LocateElem(L, cur_e) != 0 && LocateElem(L, cur_e) != 1)
        Pre_e = L.elem[LocateElem(L, cur_e) - 1];
    else
        return ERROR;
    return OK;
}

Status NextElem(SqList L, Book cur_e,Book &Next_e)
{
    // 取cur_e在线性表L中后继
    if (!L.elem)
        exit(OVERFLOW);
    else if (LocateElem(L, cur_e) != 0 && LocateElem(L, cur_e) != L.length)
        Next_e = L.elem[LocateElem(L, cur_e) + 1];
    else
        return ERROR;
    return OK;
}

Status ListInsert(SqList &L, int i, Book e)
{
    // 在线性表L的i位置前插入元素e
    if (!L.elem&&L.length==MAXSIZE)//判断表是否存在以及是否有空间
        exit(ERROR);
    else
        for(int j=L.length;j>i;j--)
            L.elem[j]=L.elem[j-1];
        L.elem[i]=e;
        ++L.length;
    return OK;
}

Status ListDelete(SqList &L, int i)
{
    // 删除线性表L中第i个元素
    if (!L.elem&&L.length==MAXSIZE)//判断表是否存在以及是否有空间
        exit(ERROR);
    else
        for(int j=i-1;j<L.length;j++)
            L.elem[j]=L.elem[j+1];
        --L.length;
    return OK;
}

Status TraverseList(SqList L)
{
    // 对线性表L的每个节点进行遍历
    if (!L.elem)
        exit(OVERFLOW);
    else for(int i=1;i<=L.length;i++)
            cout <<L.elem[i].id<<'\t'<<L.elem[i].name<<'\t'<<L.elem[i].price<<'\t'<<endl;
    return OK;
}
