#include <iostream>
#define MAXSIZE 100 // 表最大长度
#define KeyType int
#define InfoType char
#define ENDFLAG 0
using namespace std;
//================================
typedef struct
{ // 数据元素项
    KeyType key;
} ElemType;

typedef struct
{ // 顺序表的定义
    ElemType *R;
    int length;
} SSTable;

typedef struct BSTNode
{ // 二叉排序树的二叉链表存储表示
    ElemType date;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
} BSTNode, *BSTree;
//===================================

void CreatSStable(SSTable &ST, int n)
{
    // 创建顺序表
    ST.R = new ElemType[100];
    for (int i = 0; i < n; i++)
    {
        cin >> ST.R[i].key;
    }
    ST.length = n;
}
void InitBSTree(BSTree &T)
{
    // 构建空二叉排序树
    T = new BSTNode;
    T->date.key = NULL;
    T->lchild = NULL;
    T->rchild = NULL;
}
int Search_Seq(SSTable ST, KeyType key)
{ // 算法7.2 设置监视哨的顺序查找
    int i;
    ST.R[0].key = key;
    for (i = ST.length; ST.R[i].key != key; --i);
    return i;
}

int Search_Bin(SSTable ST, KeyType key)
{ // 算法7.3 折半查找
    int low = 1, high = ST.length;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == ST.R[mid].key)
            return mid;
        else if (key < ST.R[mid].key)
            high = mid - 1; // 前往左区域
        else
            low = mid + 1; // 前往右区域
    }
    return -1; // 查找失败
}

BSTree SearchBST(BSTree T, KeyType key)
{ // 算法7.4 二叉排序树的递归查找
    if ((!T) || key == T->date.key)
        return T;
    else if (key < T->date.key)
        return SearchBST(T->lchild, key);
    else
        return SearchBST(T->rchild, key);
}

void InsertBST(BSTree &T, ElemType e)
{ // 算法7.5 二叉排序树的插入
    if (!T)
    {
        BSTree S = new BSTNode;
        S->date = e;
        S->lchild = S->rchild = NULL;
        T = S;
    }
    else if (e.key < T->date.key)
        InsertBST(T->lchild, e);
    else if (e.key > T->date.key)
        InsertBST(T->rchild, e);
}
void CreatBST(BSTree &T)
{ // 算法7.6 二叉排序树的创建
    T = NULL;
    ElemType e;
    cin >> e.key;
    while (e.key != ENDFLAG)
    {
        InsertBST(T, e);
        cin >> e.key;
    }
}

void DeleteBST(BSTree &T, KeyType Key)
{ // 二叉排序树的删除
    BSTree p = T, f = NULL;
    while (p)
    {
        if (p->date.key == Key)
            break;
        f = p;
        if (p->date.key > Key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (!p)
        return;
    BSTree q = p;
    if ((p->lchild) && (p->rchild))
    {
        BSTree s = p->lchild;
    }
}

// 中序遍历的递归算法
void InOrderTraverse(BSTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout << T->date.key << " ";
        InOrderTraverse(T->rchild);
    }
}