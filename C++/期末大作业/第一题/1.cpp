/*1����֪���Ա� La �� Lb �е�����Ԫ�ذ�ֵ�ǵݼ��������У���Ҫ�� La �� Lb
�鲢Ϊһ���µ����Ա� Lc���� Lc �е�����Ԫ���԰�ֵ�ǵݼ��������С����磺
La=(1,2,3,4,5) Lb=(2, 4, 6, 8, 10)
�ϲ�֮��Lc=(1, 2, 2, 3, 4 ,4, 5,6,8, 10) */
#define MAXSIZE 100 // ���Ա���󳤶�
#define OK 1
#define ERROR 0
#define OVERFLOW (-1)
#include <iostream>

using namespace std;

typedef int Status;
typedef struct ElemType
{ // ��������Ԫ�صĽṹ��
    int data;
} ElemType;

typedef struct
{ // �������Ա������
    ElemType *elem;
    int length;
} SqList;

Status InitList(SqList *L)
{
    // �������Ա�
    L->elem = new ElemType[MAXSIZE];
    if (!L->elem)
        return ERROR;
    L->length = 0;
    return OK;
}

Status MegerList(SqList &La, SqList &Lb, SqList &Lc)
{
    // �鲢���Ա�
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < La.length || j < Lb.length; k++, Lc.length++)
    {
        if (i >= La.length){
            Lc.elem[k] = Lb.elem[j];
            j++;
        }
        else if (j >= Lb.length){
            Lc.elem[k] = La.elem[i];
            i++;
        }
        else if (La.elem[i].data < Lb.elem[j].data){
            Lc.elem[k] = La.elem[i];
            i++;
        }
        else{
            Lc.elem[k] = Lb.elem[j];
            j++;
        }
    }
    return OK;
}

int main()
{
    int i, j, k;
    // �Զ�������
    ElemType a[5] = {1, 2, 3, 4, 5};
    ElemType b[5] = {2, 4, 6, 8, 10};

    // ��ʼ���������Ա�
    SqList La, Lb, Lc;
    La.elem = a;
    La.length = 5;
    Lb.elem = b;
    Lb.length = 5;
    InitList(&Lc);

    // ���La��Lb
    cout << "La= ";
    for (i = 0; i < La.length; i++){
        printf("%d ", La.elem[i].data);
    }
    cout << "\nLb= ";
    for (i = 0; i < Lb.length; i++){
        printf("%d ", Lb.elem[i].data);
    }
    // �鲢
    MegerList(La, Lb, Lc);

    // ����鲢���Lc
    cout << "\nLc= ";
    for (i = 0; i < Lc.length; i++){
        printf("%d ", Lc.elem[i].data);
    }

    return 0;
}