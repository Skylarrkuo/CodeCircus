/*2．已知数据元素序列为{45，12，3，37，65，51，32，48，95，100，69，90 }。
要求：
（1）按各数据元素的大小顺序构造一棵二叉排序树，并中序打印排序结果。
（2）查找数据“100”是否存在。*/
#include <iostream>
#define MAXSIZE 100 // 表最大长度
#define KeyType int
#define InfoType char
#define ENDFLAG 0
using namespace std;

//=======存储结构=================
typedef struct
{ // 数据元素项
    KeyType key;
} ElemType;

typedef struct BSTNode
{ // 二叉排序树的二叉链表存储表示
    ElemType date;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
} BSTNode, *BSTree;

//========树查找操作================
void InitBSTree(BSTree &T)
{
    // 构建空二叉排序树
    T = new BSTNode;
    T->lchild = NULL;
    T->rchild = NULL;
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

BSTree SearchBST(BSTree T, KeyType key)
{ // 算法7.4 二叉排序树的递归查找
    if ((!T) || key == T->date.key)
        return T;
    else if (key < T->date.key)
        return SearchBST(T->lchild, key);
    else
        return SearchBST(T->rchild, key);
}

//===主函数=======================
int main()
{
    int n, key;
    // 创建空二叉排序树
    BSTree T;
    InitBSTree(T);
    // 创建二叉排序数
    cout << "按顺序输入元素,用空格隔开,以0结束创建:" << endl;
    cout << ">>:";
    CreatBST(T);
    cout << "中序输出创建结果:" << endl;
    InOrderTraverse(T);
    cout << endl;
    // 二叉排序树的递归查找
    cout << "输入要查找的关键字:";
    cin >> key;
    if (!SearchBST(T, key))
        cout << "查找失败!!" << endl;
    else
        cout << "查找成功~该数据存在" << endl;
    return 0;
}