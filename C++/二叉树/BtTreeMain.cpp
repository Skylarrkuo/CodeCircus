#include <iostream>
#include <windows.h>
using namespace std;

//���ö���������Ϊ�������Ĵ洢�ṹ
typedef struct BiTNode{
    char Date;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

//����ն�����
void InitBiTree(BiTree &T){
    T=new BiTNode;
    T->Date=NULL;
    T->rchild=NULL;
    T->lchild=NULL;
}
//��������򴴽�������
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
//��������ĵݹ��㷨
void PreOrderTraverse(BiTree T){
    if(T){
        cout<<T->Date;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//��������ĵݹ��㷨
void InOrderTraverse(BiTree T){
    if(T){
        InOrderTraverse(T->lchild);
        cout<<T->Date;
        InOrderTraverse(T->rchild);
    }
}

//��������ĵݹ��㷨
void PostOrderTraverse(BiTree T){
    if(T){
        PostOrderTraverse(T->lchild);
        cout<<T->Date;
        PostOrderTraverse(T->rchild);
    }
}
//���ٶ�����(�������)
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
        cout << "1.�����ն�����" << endl;
        cout << "2.����洢������" << endl;
        cout << "3.�������������" << endl;
        cout << "4.�������������" << endl;
        cout << "5.�������������" << endl;
        cout << "6.���ٶ�����" << endl;
        cout << "7.��ն�����" << endl;
        cout << "0.�˳�" << endl;
        cout << "============================" << endl;
        cout << "��������ѡ�������";
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
                cout << "�������Ѿ�������" << endl;
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
