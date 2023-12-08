#include <iostream>
using namespace std;
#define MAXSIZE 100 // ����󳤶�
#define KeyType int
#define InfoType char
#define ENDFLAG 0

//================================
typedef struct
{ // ����Ԫ����
    KeyType key;
} ElemType;

typedef struct
{ // ˳���Ķ���
    ElemType *R;
    int length;
} SSTable;

typedef struct BSTNode
{ // �����������Ķ�������洢��ʾ
    ElemType date;
    struct BSTNode *lchild;
    struct BSTNode *rchild;
} BSTNode, *BSTree;
//===================================

void CreatSStable(SSTable &ST, int n)
{
    // ����˳���
    ST.R = new ElemType[100];
    for (int i = 0; i < n; i++)
    {
        cin >> ST.R[i].key;
    }
    ST.length = n;
}
void InitBSTree(BSTree &T)
{
    // �����ն���������
    T = new BSTNode;
    T->date.key = NULL;
    T->lchild = NULL;
    T->rchild = NULL;
}
int Search_Seq(SSTable ST, KeyType key)
{ // �㷨7.2 ���ü����ڵ�˳�����
    int i;
    ST.R[0].key = key;
    for (i = ST.length; ST.R[i].key != key; --i);
    return i;
}

int Search_Bin(SSTable ST, KeyType key)
{ // �㷨7.3 �۰����
    int low = 1, high = ST.length;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (key == ST.R[mid].key)
            return mid;
        else if (key < ST.R[mid].key)
            high = mid - 1; // ǰ��������
        else
            low = mid + 1; // ǰ��������
    }
    return -1; // ����ʧ��
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

void DeleteBST(BSTree &T, KeyType Key)
{ // ������������ɾ��
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

//=====================================================
//������
int main()
{
    ElemType e;
    int ZhuangTai = true;
    int n, key;
    while (ZhuangTai)
    {
        cout << "========================" << endl;
        cout << "1.����˳���" << endl;
        cout << "2.�����ն���������" << endl;
        cout << "3.�����������Ĵ���" << endl;
        cout << "4.�����������Ĳ���" << endl;
        cout << "========================" << endl;
        cout << "5.˳�����" << endl;
        cout << "6.����(�۰�)����" << endl;
        cout << "7.�����������ĵݹ����" << endl;
        cout << "0.�˳�" << endl;
        cout << "========================" << endl;
        cout << "Input >>:";
        cin >> ZhuangTai;
        switch (ZhuangTai)
        {
        case 1: // ����˳���
            SSTable ST;
            cout << "���빲�ж�����,Ȼ�󰴴�С����˳����������:";
            cin >> n;
            CreatSStable(ST, n);
            cout << "������˳���Ϊ:";
            for (int i = 0; i < n; i++)
            {
                cout << ST.R[i].key << " ";
            }
            cout << endl;
            system("pause");
            break;
        case 2: // �����ն���������
            BSTree T;
            InitBSTree(T);
            system("pause");
            break;
        case 3: // ��������������
            cout << "��˳������Ԫ�أ��ÿո��������0����������" << endl;
            cout << ">>:";
            CreatBST(T);
            cout << "����������������" << endl;
            InOrderTraverse(T);
            system("pause");
            break;
        case 4:
            cout << "����һ��Ԫ���Բ��������������";
            cin >> e.key;
            InsertBST(T, e);
            system("pause");
            break;
        case 5:
            cout << "����Ҫ���ҵĹؼ��֣�";
            cin >> key;
            n = Search_Seq(ST, key);
            if (n == 0)
                cout << "����ʧ�ܣ���" << endl;
            else
                cout << "���ҳɹ����ڵ�" << n + 1 << "��λ��" << endl;
            system("pause");
            break;
        case 6:
            cout << "����Ҫ���ҵĹؼ��֣�";
            cin >> key;
            n = Search_Bin(ST, key);
            if (n == -1)
                cout << "����ʧ�ܣ���" << endl;
            else
                cout << "���ҳɹ����ڵ�" << n + 1 << "��λ��" << endl;
            system("pause");
            break;
        case 7:
            cout << "����Ҫ���ҵĹؼ��֣�";
            cin >> key;
            if (!SearchBST(T, key))
                cout << "����ʧ�ܣ���" << endl;
            else
                cout << "���ҳɹ�~�����ݴ���" << endl;
            system("pause");
            break;
        }
        system("cls");
    }
    return 0;
}
