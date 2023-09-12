#define MAXSIZE 100 // ���Ա���󳤶�
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
{ // ����ͼ������Ԫ�صĽṹ��
    string id;
    string name;
    double price;
} Book;

typedef struct
{ // �������Ա������
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
        cout << "===========��ӭʹ��ͼ�����ϵͳ============="<<endl;
        cout << "\t1.����ͼ���\t7.���ͼ���"<<endl;
        cout << "\t2.����������\t8.ȡ������ǰ��"<<endl;
        cout << "\t3.����ȡֵ��\t9.ȡ��������"<<endl;
        cout << "\t4.����������\t10.���������"<<endl;
        cout << "\t5.����������\t11.�˳�ϵͳ"<<endl;
        cout << "\t6.ɾ��������\t"<<endl;
        cout << "==========�����Ӧ���ֽ��в���==========\n>>:";
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
                cout << "\n��Ч�����룡��" << endl;
                sleep(3);
        }

    }
    return 0;
}
// 12�ֲ���//
Status InitList(SqList &L)
{
    // �������Ա�
    L.elem = new Book[MAXSIZE];
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    return OK;
}

Status DestroyList(SqList &L)
{
    // �������Ա�L
    if (!L.elem)
        exit(OVERFLOW);
    else
        delete[] L.elem;
    L.length = 0;
    return OK;
}

Status ClearList(SqList &L)
{
    // �������Ա�L
    if (!L.elem)
        exit(OVERFLOW);
    else
        L.length = 0;
    return OK;
}

Status ListEmpty(SqList L)
{
    // �п����Ա�L
    if (L.length == 0)
        return true;
    else
        return false;
}

Status DestroyList(SqList L)
{
    // �������Ա�LԪ�ظ���
    if (!L.elem)
        exit(OVERFLOW);
    else
        return L.length;
}

Status GetElem(SqList L, int i, Book &e)
{
    // ��e����L�е�i������Ԫ�ص�ֵ
    if (!L.elem)
        exit(OVERFLOW);
    else if (i >= 1 && i <= L.length)
        e = L.elem[i + 1];
    return OK;
}

Status LocateElem(SqList L, Book &e)
{
    // �������Ա�L��Ԫ�ز�����λ��
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
    // ȡcur_e�����Ա�L��ǰ��
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
    // ȡcur_e�����Ա�L�к��
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
    // �����Ա�L��iλ��ǰ����Ԫ��e
    if (!L.elem&&L.length==MAXSIZE)//�жϱ��Ƿ�����Լ��Ƿ��пռ�
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
    // ɾ�����Ա�L�е�i��Ԫ��
    if (!L.elem&&L.length==MAXSIZE)//�жϱ��Ƿ�����Լ��Ƿ��пռ�
        exit(ERROR);
    else
        for(int j=i-1;j<L.length;j++)
            L.elem[j]=L.elem[j+1];
        --L.length;
    return OK;
}

Status TraverseList(SqList L)
{
    // �����Ա�L��ÿ���ڵ���б���
    if (!L.elem)
        exit(OVERFLOW);
    else for(int i=1;i<=L.length;i++)
            cout <<L.elem[i].id<<'\t'<<L.elem[i].name<<'\t'<<L.elem[i].price<<'\t'<<endl;
    return OK;
}
