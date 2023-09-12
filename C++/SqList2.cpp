#define MAXSIZE 100 // ���Ա���󳤶�
#define OK 1
#define ERROR 0
#define OVERFLOW (-1)
#include <iostream>
#include <cstring>
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

}

Status ListDelete(SqList &L, int i)
{
    // ɾ�����Ա�L�е�i��Ԫ��
}

Status TraverseList(SqList L)
{
    // �����Ա�L��ÿ���ڵ���б���
}
