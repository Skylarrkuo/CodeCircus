#include <iostream>
#include <windows.h>
using namespace std;

//采用二叉链表作为二叉树的存储结构
typedef struct BiTNode{
    char Date;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

//构造空二叉树
void InitBiTree(BiTree &T){
    T=new BiTNode;
    T->Date=NULL;
    T->rchild=NULL;
    T->lchild=NULL;
}
//以先序次序创建二叉树
void CreateBiTree_PreOrder(BiTree &T){
    InitBiTree(T);
    cin >> T->Date;
    if(T->Date != '#'){
        CreateBiTree_PreOrder(T->lchild);
        CreateBiTree_PreOrder(T->rchild);
    }else{
        T=NULL;
    }
}
//先序遍历的递归算法
void PreOrderTraverse(BiTree T){
    if(T){
        cout<<T->Date;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//中序遍历的递归算法
void InOrderTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);
        cout<<T->Date;
        InOrderTraverse(T->rchild);
    }
}

//后序遍历的递归算法
void PostOrderTraverse(BiTree T){
    if(T){
        PostOrderTraverse(T->lchild);
        cout<<T->Date;
        PostOrderTraverse(T->rchild);
    }
}
//销毁二叉树(后序遍历)
void DestroyBiTree(BiTree &T){
    if(T){
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        delete T;
    }
}

int main()
{
    int ZhuangTai = true;
    while (ZhuangTai)
    {
        cout << "1.创建空二叉树" << endl;
        cout << "2.先序存储二叉树" << endl;
        cout << "3.先序遍历二叉树" << endl;
        cout << "4.中序遍历二叉树" << endl;
        cout << "5.后序遍历二叉树" << endl;
        cout << "6.销毁二叉树" << endl;
        cout << "7.清空二叉树" << endl;
        cout << "0.退出" << endl;
        cout << "============================" << endl;
        cout << "输入数子选择操作：";
        cin >> ZhuangTai;
        switch (ZhuangTai)
        {
        case 1:
            BiTNode *T;
            system("pause");
            break;
        case 2:
            CreateBiTree_PreOrder(T);
            system("pause");
            break;
        case 3:
            if (T->Date)
            {
                PreOrderTraverse(T);
            }
            system("pause");
            break;
        case 4:
            if (T->Date)
            {
                PreOrderTraverse(T);
            }
            system("pause");
            break;
        case 5:
            if (T->Date)
            {
                InOrderTraverse(T);
            }
            system("pause");
            break;
        case 6:
            if (T->Date)
            {
                DestroyBiTree(T);
            }
            else
            {
                cout << "二叉树已经不存在" << endl;
            }
            system("pause");
            break;
        case 7:
            break;
        }
        system("cls");
    }
    return 0;
}
