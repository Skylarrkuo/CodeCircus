//By Skylarrkuo
#include <iostream>
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

