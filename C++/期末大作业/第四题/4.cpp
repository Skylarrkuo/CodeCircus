/*2����֪����Ԫ������Ϊ{45��12��3��37��65��51��32��48��95��100��69��90 }��
Ҫ��
��1����������Ԫ�صĴ�С˳����һ�ö������������������ӡ��������
��2���������ݡ�100���Ƿ���ڡ�*/
#include <iostream>
#define MAXSIZE 100 // ����󳤶�
#define KeyType int
#define InfoType char
#define ENDFLAG 0
using namespace std;

//=======�洢�ṹ=================
typedef struct
{ // ����Ԫ����
    KeyType key;
} ElemType;

typedef struct BSTNode
{ // �����������Ķ�������洢��ʾ
    ElemType date;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
} BSTNode, *BSTree;

//========�����Ҳ���================
void InitBSTree(BSTree &T)
{
    // �����ն���������
    T = new BSTNode;
    T->lchild = NULL;
    T->rchild = NULL;
}

void InsertBST(BSTree &T, ElemType e)
{ // �㷨7.5 �����������Ĳ���
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
{ // �㷨7.6 �����������Ĵ���
    T = NULL;
    ElemType e;
    cin >> e.key;
    while (e.key != ENDFLAG)
    {
        InsertBST(T, e);
        cin >> e.key;
    }
}

// ��������ĵݹ��㷨
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
{ // �㷨7.4 �����������ĵݹ����
    if ((!T) || key == T->date.key)
        return T;
    else if (key < T->date.key)
        return SearchBST(T->lchild, key);
    else
        return SearchBST(T->rchild, key);
}

//===������=======================
int main()
{
    int n, key;
    // �����ն���������
    BSTree T;
    InitBSTree(T);
    // ��������������
    cout << "��˳������Ԫ��,�ÿո����,��0��������:" << endl;
    cout << ">>:";
    CreatBST(T);
    cout << "��������������:" << endl;
    InOrderTraverse(T);
    cout << endl;
    // �����������ĵݹ����
    cout << "����Ҫ���ҵĹؼ���:";
    cin >> key;
    if (!SearchBST(T, key))
        cout << "����ʧ��!!" << endl;
    else
        cout << "���ҳɹ�~�����ݴ���" << endl;
    return 0;
}